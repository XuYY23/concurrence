#pragma once

#include "cancel.h"
#include "status.h"

namespace arrow
{

/*
   Hints about a task that may be used by an Executor.
   They are ignored by the provided ThreadPool implementation.
*/
struct TaskHints
{
   // The lower, the more urgent
   int32_t priority = 0;

   // The IO transfer size in bytes
   int64_t io_size = -1;

   // The approximate CPU cost in number of instructions
   int64_t cpu_cost = -1;
   
   // An application-specific ID
   int64_t external_id = -1;
};

/*
   Note :
      Spawn() is used to produce tasks without return values.
      Submit() is used to produce tasks with return values.
      They actually call SpawnReal() as the underlying implementation.
*/
class ARROW_EXPORT Executor
{
public:
   using StopCallback = internal::FnOnce<void(const Status&)>;

   virtual ~Executor();

   /*
      Spawn a fire-and-forget task.
   */
   template <typename Function>
   Status Spawn(Function&& func)
   {
      return SpawnReal(TaskHints{}, std::forward<Function>(func), StopToken::Unstoppable(), StopCallback{});
   }

   template <typename Function>
   Status Spawn(Function&& func, StopToken stop_token)
   {
      return SpawnReal(TaskHints{}, std::forward<Function>(func), std::move(stop_token), StopCallback{});
   }

   template <typename Function>
   Status Spawn(TaskHints hints, Function&& func)
   {
      return SpawnReal(hints, std::forward<Function>(func), StopToken::Unstoppable(), StopCallback{});
   }

   template <typename Function>
   Status Spawn(TaskHints hints, Function&& func, StopToken stop_token)
   {
      return SpawnReal(hints, std::forward<Function>(func), std::move(stop_token), StopCallback{});
   }

   template <typename Function>
   Status Spawn(TaskHints hints, Function&& func, StopToken stop_token, StopCallback stop_callback)
   {
      return SpawnReal(hints, std::forward<Function>(func), std::move(stop_token), std::move(stop_callback));
   }

   virtual Status SpawnReal(TaskHints hints, internal::FnOnce<void()> task, StopToken, StopCallback&&) = 0;

   template <typename Function, typename... Args,
             typename ReturnType = typename std::result_of<Function(Args...)>::type>
   std::future<ReturnType> Submit(TaskHints hints, StopToken stop_token,
                                  StopCallback stop_callback, Function&& func,
                                  Args&&... args)
   {
      std::promise<ReturnType> promise;
      std::future<ReturnType> future = promise.get_future();

      // Wrapper the given func and args togther to be a task.
      auto task = [func = std::forward<Function>(func),
                   tup = std::make_tuple(std::forward<Args>(args)...),
                   promise = std::move(promise)]() mutable -> void
      {
         try
         {
            /*
               if constexpr is a new if statement introduced by C++17, known as compile time if or constexpr if. 
               The characteristic of constexpr if is that its conditional expression is evaluated during compilation

               The purpose of this if-constexpr is to check if ReturnType is void type. 
               If ReturnType is not of void type, the code block within the if-constexpr statement will be compiled. 
               Otherwise, this part of the code will be ignored by the compiler, which means it will not appear in the compiled program.
            */
            if constexpr ( !std::is_void_v<ReturnType> )
            {
               ReturnType result = std::apply(std::move(func), std::move(tup));
               promise.set_value(result);
            }
            else
            {
               std::apply(std::move(func), std::move(tup));
            }
         }
         catch(...)
         { 
            promise.set_exception(std::current_exception());
         }
      }; // lambda

      Status status = 
         SpawnReal(hints, std::move(task), stop_token, std::move(stop_callback));
      if( !status.ok() )
      {
         throw std::runtime_error("Failed to submit task");
      }

      return future;
   }

    template <typename Function, typename... Args,
            typename ReturnType = typename std::result_of<Function(Args...)>::type>
   std::future<ReturnType> Submit(Function&& func, Args&&... args) 
   {
      return Submit(TaskHints{}, StopToken::Unstoppable(), StopCallback{},
                    std::forward<Function>(func), std::forward<Args>(args)...);
   }

   template <typename Function, typename... Args,
             typename ReturnType = typename std::result_of<Function(Args...)>::type>
   std::future<ReturnType> Submit(StopToken stop_token, Function&& func, Args&&... args)
   {
      return Submit(TaskHints{}, stop_token, StopCallback{}, 
                    std::forward<Function>(func), std::forward<Args>(args)...);
   }   

   template <typename Function, typename... Args,
             typename ReturnType = typename std::result_of<Function(Args...)>::type>
   std::future<ReturnType> Submit(TaskHints hints, Function&& func, Args&&... args)
   {
      return Submit(std::move(hints), StopToken::Unstoppable(), StopCallback{},
                    std::forward<Function>(func), std::forward<Args>(args)...);
   }             

   template <typename Function, typename... Args,
            typename ReturnType = typename std::result_of<Function(Args...)>::type>
   std::future<ReturnType> Submit(StopCallback stop_callback, Function&& func, Args&&... args) 
   {
      return Submit(TaskHints{}, StopToken::Unstoppable(), std::move(stop_callback),
                    std::forward<Function>(func), std::forward<Args>(args)...);
   }     
};

}  // namespace arrow