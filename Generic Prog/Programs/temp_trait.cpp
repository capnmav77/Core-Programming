#include <type_traits>

int main() 
{
  std::enable_if<false, int>::type MyInt{42};
}
