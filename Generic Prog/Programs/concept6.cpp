// To compile this, you need to define the C++ standard
// g++ --std=c++20 *.cpp

#include <concepts>

template <typename T>
  requires std::integral<T> || std::floating_point<T>
T Average(T x, T y) 
{
  return (x + y) / 2;
}

int main(void) 
{
  Average(1, 2);
  Average(3.4, 5.3);
  return 0;
}