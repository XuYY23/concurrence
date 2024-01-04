#include <memory>
#include <mutex>
#include <condition_variable>

template<typename T>
class thread_safe_queue
{
private:
   struct node
   {
      std::shared_ptr<T> data;
      std::unique_ptr<node> next;
   };
   std::mutex head_mutex;
   std::unique_ptr<node> head;
   std::mutex tail_mutex;
   node* tail;
   std::condition_variable data_cond;

private:
   node* get_tail();
   std::unique_ptr<node> pop_head();
   std::unique_lock<std::mutex> wait_for_data();
   std::unique_ptr<node> wait_pop_head();
   std::unique_ptr<node> wait_pop_head(T&);

   std::unique_ptr<node> try_pop_head();
   std::unique_ptr<node> try_pop_head(T&);

public:
   thread_safe_queue():
      head(new node), tail(head.get())
   {}
   thread_safe_queue(const thread_safe_queue&) = delete;
   thread_safe_queue& operator=(const thread_safe_queue&) = delete;

   std::shared_ptr<T> try_pop();
   bool try_pop(T&);

   std::shared_ptr<T> wait_and_pop();
   void wait_and_pop(T&);

   void push(T);

   bool empty();
};

template<typename T>
void 
thread_safe_queue<T>::push(T new_value)
{
   std::shared_ptr<T> new_data(std::make_shared<T>(std::move(new_value)));
   std::unique_ptr<node> p(new node);
   {
      std::lock_guard<std::mutex> tail_lock(tail_mutex);
      tail->data = new_data;
      node* const new_tail = p.get();
      tail->next = std::move(p);
      tail = new_tail;
   }
   data_cond.notify_one();
}

template<typename T>
typename thread_safe_queue<T>::node* 
thread_safe_queue<T>::get_tail()
{
   std::lock_guard<std::mutex> tail_lock(tail_mutex);
   return tail;
}

template<typename T>
std::unique_ptr<typename thread_safe_queue<T>::node> 
thread_safe_queue<T>::pop_head()
{
   std::unique_ptr<node> old_head = std::move(head);
   head = std::move(old_head->next);
   return old_head;
}

template<typename T>
std::unique_lock<std::mutex> 
thread_safe_queue<T>::wait_for_data()
{
   std::unique_lock<std::mutex> head_lock(head_mutex);
   data_cond.wait(head_lock, [&]{return head.get() != get_tail();});
   return std::move(head_lock);
}

template<typename T>
std::unique_ptr<typename thread_safe_queue<T>::node> 
thread_safe_queue<T>::wait_pop_head()
{
   std::unique_lock<std::mutex> head_lock(wait_for_data());
   return pop_head();
}

template<typename T>
std::unique_ptr<typename thread_safe_queue<T>::node>
thread_safe_queue<T>::wait_pop_head(T& value)
{
   std::unique_lock<std::mutex> head_lock(wait_for_data());
   value = std::move(*head->data);
   return pop_head();
}

template<typename T>
std::shared_ptr<T>
thread_safe_queue<T>::wait_and_pop()
{
   std::unique_ptr<node> const old_head = wait_pop_head();
   return old_head->data;
}

template<typename T>
void
thread_safe_queue<T>::wait_and_pop(T& value)
{
   std::unique_ptr<node> const old_head = wait_pop_head(value);
}

template<typename T>
std::unique_ptr<typename thread_safe_queue<T>::node>
thread_safe_queue<T>::try_pop_head()
{
   std::lock_guard<std::mutex> head_lock(head_mutex);
   if(head.get() == get_tail())
   {
      return std::unique_ptr<node>();
   }
   return pop_head();
}

template<typename T>
std::unique_ptr<typename thread_safe_queue<T>::node>
thread_safe_queue<T>::try_pop_head(T& value)
{
   std::lock_guard<std::mutex> head_lock(head_mutex);
   if(head.get() == get_tail())
   {
      return std::unique_ptr<node>();
   }
   value = std::move(*head->data);
   return pop_head();
}

template<typename T>
std::shared_ptr<T>
thread_safe_queue<T>::try_pop()
{
   std::unique_ptr<node> old_head = try_pop_head();
   return old_head ? old_head->data : std::shared_ptr<T>();
}

template<typename T>
bool
thread_safe_queue<T>::try_pop(T& value)
{
   std::unique_ptr<node> const old_head = try_pop_head(value);
   return old_head != nullptr;
}

template<typename T>
bool
thread_safe_queue<T>::empty()
{
  std::lock_guard<std::mutex> head_lock(head_mutex);
  return (head.get() == get_tail());
}
