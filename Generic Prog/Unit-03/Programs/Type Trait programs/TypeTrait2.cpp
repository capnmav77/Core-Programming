#include <type_traits>
#include <iostream>
#include <cstdint>

int main(void) 
{
  if (std::is_arithmetic_v<double>) 
  {
    std::cout << "double is arithmetic\n";
  }
  if (std::is_arithmetic<std::int32_t>()) 
  {
    std::cout << "int32_t is also arithmetic";
  }
  return 0;
}