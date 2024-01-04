#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "status.h"
#include "visibility.h"

namespace arrow 
{

class StopToken;

struct StopSourceImpl;

/*
   Experimental
*/
class ARROW_EXPORT StopSource
{
protected:
   std::shared_ptr<StopSourceImpl> impl_;

public:
   StopSource();
   ~StopSource();

   /*
      Consumer API (the side that stops)
   */
   void RequestStop();
   void RequestStop(Status error);
   void RequestStopFromSignal(int signum);

   StopToken token();

   /* For internal use only */
   void Reset();
};

class ARROW_EXPORT StopToken
{
protected:
   std::shared_ptr<StopSourceImpl> impl_;

public:
   StopToken() {}

   explicit StopToken(std::shared_ptr<StopSourceImpl> impl) : impl_(std::move(impl)) {}

   // A trivial token that never propagates any stop request
   static StopToken Unstoppable() { return StopToken(); }

   // Producer API (the side that gets asked to stopped)
   Status Poll() const;

   /*
      Brief :
         Determine whether to request a stop
   */
   bool IsStopRequested() const;
};

}  // namespace arrow