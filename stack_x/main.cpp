#include "lock_free_stack.h"
#include <iostream>
#include <thread>

lock_free_stack<int> my_stack;

void work1()
{
    for (int i = 0; i < 10000; i++) {
        my_stack.push(i);
    }
}

void work2()
{
   int cnt = 0;
    for (int i = 0; i < 10000; i++) {
        std::shared_ptr<int> res = my_stack.pop();
        if (res) {
            std::cout << *res << std::endl;
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}

int main()
{
    std::thread t1(work1), t2(work2);
    t1.join();
    t2.join();
    return 0;
}