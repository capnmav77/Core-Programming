// To compile this, you need to define the C++ standard
// g++ --std=c++20 *.cpp

#include <concepts>

template <std::integral T>
class Container 
{
  T Contents;
};

int main(void) 
{
  Container<int> Stuff;
  Container<float> MoreStuff;
  return 0;
}