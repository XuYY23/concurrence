#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "cancel.h"
#include "io_util.h"
#include "macros.h"
#include "thread_pool.h"
using namespace arrow;

int main() {
   // Create a thread pool
   auto threadPool = GetCpuThreadPool();
   if (!threadPool) {
      std::cerr << "Failed to create thread pool" << std::endl;
      return 1;
   }

   // Submit tasks to the thread pool
   threadPool->Spawn([]() { std::cout << "hello world!" << std::endl; });

   // Wait for all tasks to complete
   threadPool->WaitForIdle();

   // Shutdown the thread pool
   threadPool->Shutdown();
}
