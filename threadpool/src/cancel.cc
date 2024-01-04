#include "cancel.h"

#include <atomic>
#include <mutex>
#include <sstream>
#include <utility>
#include "macros.h"

namespace arrow 
{

/*
   ATOMIC_INT_LOCK_FREE is a macro used to indicate whether an atomic operation of type int is unlocked. 
   Its value can be 0, 1, or 2 : 
      if ATOMIC_INT_LOCK_FREE is 0, indicating that atomic operations of type int are never unlocked. 
      if ATOMIC_INT_LOCK_FREE is 1, indicating that atomic operations of type int are sometimes unlocked. 
      if ATOMIC_INT_LOCK_FREE is 2, indicating that atomic operations of type int are always unlocked.
*/
#if ATOMIC_INT_LOCK_FREE != 2
#error Lock-free atomic int required for signal safety
#endif

/*
   NOTE: 
      We care mainly about the making the common case (not cancelled) fast.
*/

struct StopSourceImpl 
{
   /*
      Brief :
         requested_ will be 0, -1 or signam number if requested.
      
      Note :
         If requested_ is not equal to 0, it means stop.
   */
   std::atomic<int> requested_{0};  
   std::mutex mutex_;
   Status cancel_error_;
};

StopSource::StopSource() : impl_(new StopSourceImpl) {}

StopSource::~StopSource() = default;

void StopSource::RequestStop() { RequestStop(Status::Cancelled("Operation cancelled")); }

void StopSource::RequestStop(Status st) 
{
   std::lock_guard<std::mutex> lock(impl_->mutex_);
   DCHECK_NOT_OK(st);
   if ( !impl_->requested_ ) 
   {
      impl_->requested_ = -1;
      impl_->cancel_error_ = std::move(st);
   }
}

void StopSource::RequestStopFromSignal(int signum) 
{
   // Only async-signal-safe code allowed here
   impl_->requested_.store(signum);
}

void StopSource::Reset() 
{
   std::lock_guard<std::mutex> lock(impl_->mutex_);
   impl_->cancel_error_ = Status::OK();
   impl_->requested_.store(0);
}

StopToken StopSource::token() { return StopToken(impl_); }

bool StopToken::IsStopRequested() const 
{
   if ( !impl_ ) 
   {
      return false;
   }
   return impl_->requested_.load() != 0;
}

Status StopToken::Poll() const 
{
   if ( !impl_ ) 
   {
      return Status::OK();
   }

   if ( !impl_->requested_.load() ) 
   {
      return Status::OK();
   }

   std::lock_guard<std::mutex> lock(impl_->mutex_);
   if ( impl_->cancel_error_.ok() ) 
   {
      auto signum = impl_->requested_.load();
      DCHECK_GE(signum, 0);
      impl_->cancel_error_ = Status::Cancelled("Operation cancelled");
   }
   return impl_->cancel_error_;
}

}  // namespace arrow
