#include <memory>
#include <atomic>

template<typename T>
struct node;

template<typename T>
struct counted_node_ptr
{
    int external_count; //外部计数器
    node<T>* ptr;
};

template<typename T>
struct node
{
    std::shared_ptr<T> data;
    std::atomic<int> internal_count; //内部计数器，与上面的外部计数器结合来判断当前节点是否有其他线程指涉，如果加上外部计数器等于0就可以删除节点
    counted_node_ptr<T> next;
    node(const T& data_) :
        data(std::make_shared<T>(data_)),
        internal_count(0)
    {}
};

template<typename T>
class lock_free_stack
{
private:
    std::atomic<counted_node_ptr<T>> head;
    void increase_head_count(counted_node_ptr<T>&); //更新指针的外部计数器

public:
    ~lock_free_stack();

    void push(const T& data);

    std::shared_ptr<T> pop();
};


/*-------------------The following code is the implementation-----------------*/


template<typename T>
void lock_free_stack<T>::increase_head_count(counted_node_ptr<T>& old_counter)
{
    counted_node_ptr<T> new_counter;

    do {
        new_counter = old_counter;
        ++new_counter.external_count;
    } while (!head.compare_exchange_strong(old_counter, new_counter, std::memory_order_acquire, std::memory_order_relaxed));
    //该循环确保在增加外部计数器的时候head没有遭受其他线程的改动

    old_counter.external_count = new_counter.external_count; //这里不仅有更新head，old_head也要更新，因为这两个指针正在指向head所指的头节点
}

template<typename T>
lock_free_stack<T>::~lock_free_stack()
{
    while (pop());
}

template<typename T>
void lock_free_stack<T>::push(const T& data)
{
    counted_node_ptr<T> new_node;
    new_node.ptr = new node<T>(data);
    new_node.external_count = 1;
    new_node.ptr->next = head.load(std::memory_order_relaxed);
    //该循环用于确保head指针正确被更新，放在其他线程在这里趁机修改head
    while (!head.compare_exchange_strong(new_node.ptr->next, new_node, std::memory_order_release, std::memory_order_relaxed));
}

template<typename T>
std::shared_ptr<T> lock_free_stack<T>::pop()
{
    counted_node_ptr<T> old_head = head.load(std::memory_order_relaxed);
    for (;;) {
        increase_head_count(old_head); //先自增外部计数器

        node<T>* const ptr = old_head.ptr;
        //如果ptr为空，说明栈为空
        if (!ptr) {
            return std::shared_ptr<T>();
        }
        //试图获得head的控制权
        if (head.compare_exchange_strong(old_head, ptr->next, std::memory_order_relaxed)) {
            std::shared_ptr<T> res;
            res.swap(ptr->data); //先获得data
            const int count_increase = old_head.external_count - 2; //这里减2是因为我们将头节点弹出，这里-1，然后该线程也就是old_head不再指涉，再-1
            //如果内部引用计数器+外部引用计数器变成0，也就是内部引用计数器的原值等于-count_increase，就可以删除该节点
            if (ptr->internal_count.fetch_add(count_increase, std::memory_order_release) == -count_increase) {
                delete ptr;
            }
            return res;
        }
        else if (ptr->internal_count.fetch_add(-1, std::memory_order_relaxed) == 1) { //如果该当前线程最后一个持有的线程，则棋内部引用计数器会变为1
            ptr->internal_count.load(std::memory_order_acquire);
            delete ptr;
        }
    }
}