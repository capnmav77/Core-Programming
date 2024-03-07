#include <type_traits>

template <typename TFirst, typename TSecond>
auto Average(TFirst x, TSecond y) 
{
  static_assert(
      std::is_arithmetic<TFirst>::value,
      "Average: First argument must be arithmetic");
  static_assert(
      std::is_arithmetic<TSecond>::value,
      "Average: Second argument must be arithmetic");
  return (x + y) / 2;
}

int main (void)
{
  int res = Average (12, "abc");
  return 0;
}

