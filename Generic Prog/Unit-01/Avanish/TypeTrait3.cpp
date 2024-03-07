#include <type_traits>
#include <iostream>

template <typename T>
void Function(T Param) 
{
  if (std::is_arithmetic<T>::value) 
  {
    std::cout << "Type is arithmetic\n";
  } 
  else 
  {
    std::cout << "Type is not arithmetic\n";
  }
}

int main(void) 
{
  Function(100);
  Function("Hello World");
  return 0;
}