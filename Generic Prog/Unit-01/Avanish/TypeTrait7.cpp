#include <type_traits>
#include<iostream>
template <typename TFirst, typename TSecond>
auto Average(TFirst x, TSecond y) 
{
  static_assert(
      std::is_arithmetic<TFirst>::value && std::is_arithmetic<TSecond>::value,
      "Average: Both argument must be arithmetic");
 
  return (x + y) / 2;
}

int main (void)
{
  // int res = Average (12, "abc");

  std::enable_if<false,int>::type Myint{42};


  return 0;
}

