#pragma once

#ifndef ARROW_EXPORT

/*
   __attribute__((visibility("default"))) :
      this is a feature of GCC.
      is used to control the visibility of symbols(like functions or variables)at link time.
      "default"visibility means that the symbol is visible to other modules linked to this shared library.
      this is useful for exposing APIs when creating shared libraries(like dynamic link libraries or .so files).
   
   Example: 
      __attribute__((visibility("default"))) void func();
      or ARROW_EXPORT void func();

      func have default visibility that is visible to other modules when linked and can be accessed by other code linked to the library.
*/
#define ARROW_EXPORT  __attribute__((visibility("default")))

#endif