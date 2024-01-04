#pragma once

namespace arrow
{

namespace internal
{

/*
   A type erased callable object which may only be invoked once.
   It can be constructed from any lambda which matches the provided call signature.
   Invoking it results in destruction of the lambda, freeing any state/references immediately.
   Invoking a default constructed FnOnce or one which has already been invoked will segfault.
   The design pattern of this class is called "type erasure"
*/
template <typename Signature>
class FnOnce;

template <typename R, typename... A>
class FnOnce<R(A...)>
{
private:
   struct Impl
   {
      virtual ~Impl() = default;
      virtual R invoke(A&&... a) = 0;
   };

   template <typename Fn>
   struct FnImpl : Impl
   {
      Fn fn_;
      explicit FnImpl(Fn fn) : fn_(std::move(fn)) {}
      R invoke(A&&... a) override 
      {
         return std::move(fn_)(std::forward<A&&>(a)...);
      }
   };

   std::unique_ptr<Impl> impl_;

public:
   FnOnce() = default;

   /*
      This section of the code checks whether Fn can be called and returns a value of type R. 
      If possible, std:: enable_ if will make this constructor valid; 
      If not possible, this constructor will be ignored and will not cause compilation errors.

      Explain:
         std::enable_if<Boolean> : If the Boolean is true, std::enable_if there is a member named type, otherwise there will be no.
         std::is_convertible<From, To> : this is a type feature class used to check whether one type can be implicitly converted to another type.
                                         If it can be converted, std::is_convertible<From, To>::value is true, otherwise it is false.
         std::declval<T> : It can convert any type T to a right value reference type

         So, in this case, we use std::declval<Fn&&>() created an Fn type right value reference, and then std::declval<A>() created a set of right value references of type A, just like this Fn(A, A1, ...).
         Then, we use decltype to To obtain the return value types mentioned above to comparison with R.
   */
   template <typename Fn,
             typename = typename std::enable_if<std::is_convertible<
                           decltype(std::declval<Fn&&>()(std::declval<A>()...)), R>::value>::type>
   FnOnce(Fn fn) : impl_(new FnImpl<Fn>(std::move(fn))) {}

   explicit operator bool() const { return impl_ != nullptr; }

   R operator()(A... a) && 
   {
      auto bye = std::move(impl_);
      return bye->invoke(std::forward<A&&>(a)...);
   }
};

}  // namespace internal

}  // namespace arrow