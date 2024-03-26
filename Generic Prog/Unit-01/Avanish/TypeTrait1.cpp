#include <type_traits>
#include <iostream>
#include <vector>

int main(void) 
{
  if (std::is_arithmetic<float>::value) 
  {
    std::cout << "float is arithmetic";
  }

  if (!std::is_arithmetic<std::string>::value) 
  {
    std::cout << " but std::string isn't";
  }

  using vector_trait =
      std::is_arithmetic<std::vector<int>>;

  if (!vector_trait::value) 
  {
    std::cout
        << "\nNeither is std::vector<int>";
  }
  return 0;
}