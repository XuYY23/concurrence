#pragma once

#include <unistd.h>
#include <cstdint>
#include <functional>
#include <future>
#include <memory>
#include <optional>
#include <queue>
#include <type_traits>
#include <utility>

#include "cancel.h"
#include "functional.h"
#include "status.h"
#include "visibility.h"
#include "executor.h"

namespace arrow
{

class StopToken;

/*
   Brief : 
      get the capacity of the global thread pool.

   Detailed : 
      Return the number of worker threads in the thread pool to which arrow dispatches various CPU-bound tasks.
      This is a ideal number, not necessarily the exact number of threads at a given point in time.
   
   Note :
      you can change this number using SetCpuThreadPoolCapacity().
*/
ARROW_EXPORT int GetCpuThreadPoolCapacity();

/*
   Brief : 
      Set the capacity of the global thread pool.

   Detailed :
      Set the number of worker threads in the thread pool to which arrow dispatches various CPU-bound tasks.
   
   Note :
      The current number is returned by GetCpuThreadPoolCapacity().
*/
ARROW_EXPORT Status SetCpuThreadPoolCapacity(int threads);

/*
   Brief : 
      An Executor implementation spawning tasks in FIFO manner on a fixed-size pool of worker threads.

   Note :
      Any sort of nested parallelism will deadlock this executor.
      Blocking waits are fine but if one task needs to wait for another task it must be expressed as an asynchronous continuation.
*/
class ARROW_EXPORT ThreadPool : public Executor 
{
public:
   /*
      Brief : 
         Properties of Thread Pool.
   */
   struct State;

   /*
      Brief : 
         Construct a thread pool with the given number of worker threads
   */
   static std::optional<std::shared_ptr<ThreadPool>> Make(int threads);

   /*
      Brief :
         Like Make(), but takes care that the returned ThreadPool is compatible with destruction late at process exit
   */
   static std::optional<std::shared_ptr<ThreadPool>> MakeIternal(int threads);

   /*
      Brief :
         Destroy thread pool; the pool will first be shut down
   */
   ~ThreadPool();

   /*
      Brief : 
         Return the desired number of worker threads.

      Note :
         The actual number of workers may lag a bit before being adjusted to match this value
   */
   int GetCapacity();

   /*
      Brief :
         Determine if the current thread pool is this
   */
   bool OwnsThisThread();

   /*
      Brief :
         Return the number of tasks either running or in the queue
   */
   int GetNumTasks();

   /*
      Brief :
         Dynamically change the number of worker threads.

      Detailed :
         This function always returns immediately.
         If fewer threads are running than this number, new threads are spawned on-demand when needed for task execution.
         If more threads are running than this number, excess threads are reaped as soon as possible.
   */
   Status SetCapacity(int threads);

   /*
      Brief :
         Heuristic for the default capacity of a thread pool for CPU-bound tasks.
         This is exposed as a static method to help with testing.
   */ 
   static int DefaultCapacity();

   /*
      Brief :
         Shutdown the pool.

      Detailed :
          Once the pool starts shutting down, new tasks cannot be submitted anymore.
          If "wait" is true, shutdown waits for all pending tasks to be finished.
          If "wait" is false, workers are stopped as soon as currently executing tasks are finished.
   */
   Status Shutdown(bool wait = true);

   /*
      Brief :
         Wait for the thread pool to become idle.

      Note :
         This is useful for sequencing tests.
   */
   void WaitForIdle();

protected:
   friend ARROW_EXPORT ThreadPool* GetCpuThreadPool();

   ThreadPool();

   /*
      Brief :
         Override the father's class SpawnReal.
   */
   Status SpawnReal(TaskHints hints, internal::FnOnce<void()> task, StopToken, StopCallback&&);

   /*
      Brief :
         Collect finished worker threads, making sure the OS threads have exited.
   */
   void CollectFinishedWorkersUnlocked();

   /*
      Brief :
         Launch a given number of additional workers.
   */
   void LaunchWorkersUnlocked(int threads);

   /*
      Brief :
         Get the current actual capacity.
   */
   int GetActualCapacity();

   /*
      Brief :
         Reinitialize the thread pool if the pid changed.
   */
   void ProtectAgainstFork();

   
   /*
      Brief :
         Helper for the singleton pattern
   */
   static std::shared_ptr<ThreadPool> MakeCpuThreadPool();

   std::shared_ptr<State> sp_state_;
   State* state_;
   bool shutdown_on_destroy_;
   pid_t pid_;

};

/*
   Brief :
      Return the process-global thread pool for CPU-bound tasks.
*/
ARROW_EXPORT ThreadPool* GetCpuThreadPool();

}  // namespace arrow