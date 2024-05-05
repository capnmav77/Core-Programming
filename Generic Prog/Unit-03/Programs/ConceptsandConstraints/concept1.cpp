// To compile this, you need to define the C++ standard
// g++ --std=c++20 *.cpp

#include <iostream>
#include <concepts>

int main(void) 
{
  if constexpr (std::integral<int>) 
  {
    std::cout << "int is an integral";
  }

  if constexpr (!std::integral<float>) 
  {
    std::cout << "\nfloat isn't";
  }
  return 0;
}