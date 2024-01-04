#pragma once


/*
   Brief :
      Help eliminate compiler warnings caused by unused parameters.
*/
#define ARROW_UNUSED(x) (void)(x)

/*
   __builtin_expect : 
      1. provided by some compilers, notably GCC.
      2. is a way to provide the compiler with branch prediction information.
         In other words, it's a hint to the compiler about the expected result of a comparison in a conditional statement, 
            which can help optimize the code for modern processors.
      3. The function takes two arguments: a long integer expression and a constant. 
         The return value is the first argument (the expression). 
         The semantics are that if the compiler knows the comparison is likely to be true, it can optimize the code accordingly.

   In the case of ARROW_PREDICT_FALSE(x), the expression is !!(x), which will be 1 if x is non-zero and 0 if x is zero. 
   The constant is 0, indicating that the expression is expected to be false.
   So, ARROW_PREDICT_FALSE(x) is a hint to the compiler that the condition x is expected to be false.
   if x is true, it's a prediction failure, and the CPU might need to flush the pipeline, which might be much costly.
*/
#define ARROW_PREDICT_FALSE(x) (__builtin_expect(!!(x), 0))

/*
   check the val1 is greater equal val2
*/
#define DCHECK_GE(val1, val2) \
   do \
   { \
      if( !( (val1) >= (val2) ) ) \
      { \
         std::abort(); \
      } \
   }while(false)

#define DCHECK_EQ(val1, val2) \
   do \
   { \
      if( !( (val1) == (val2) ) ) \
      { \
         std::abort(); \
      } \
   }while(false)

#define DCHECK_OK(val) \
   do \
   { \
      if( !( (val).ok() ) ) \
      { \
         std::abort(); \
      } \
   }while( false )

#define DCHECK_NOT_OK(val) \
   do \
   { \
      if( ( (val).ok() ) ) \
      { \
         std::abort(); \
      } \
   }while( false )