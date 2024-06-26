// To compile this, you need to define the C++ standard
// g++ --std=c++20 *.cpp

#include <iostream>
#include <concepts>

template <typename T>
  requires std::integral<T>
T Average(T x, T y) 
{
  std::cout << "Using integral function\n";
  return (x + y) / 2;
}

template <typename T>
  requires std::floating_point<T>
T Average(T x, T y) 
{
  std::cout << "Using floating point function";
  return (x + y) / 2;
}

int main(void) 
{
  Average(1, 2);
  Average(3.4, 5.3);
  // Average (1, 3.4);
  return 0;
}