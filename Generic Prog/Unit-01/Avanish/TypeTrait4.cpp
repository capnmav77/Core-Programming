#include <type_traits>
#include <iostream>

template <typename T>
void Function(T Param) 
{
  if( constexpr std::is_integral<T>::value) 
  {
    std::cout << "Integer!\n";
  }

  if(constexpr std::is_floating_point<T>::value) 
  {
    std::cout << "Floating point number!\n";
  }
}

int main(void) 
{
  Function(42);
  Function(3.14);
  return 0;
}