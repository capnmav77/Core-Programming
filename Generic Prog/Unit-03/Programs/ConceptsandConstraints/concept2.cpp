// To compile this, you need to define the C++ standard
// g++ --std=c++20 *.cpp

#include <concepts>

template <std::integral T>
T Average(T x, T y) 
{
  return (x + y) / 2;
}

int main(void) 
{
  Average(1, 2);
  Average(1.5, 2.2); 
  return 0;
}