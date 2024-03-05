using namespace std;

#include <iostream>
#include <cstdint>
#include <type_traits> // for std::conditional
#include <typeinfo> // for typeid

constexpr bool Use64BitIntegers{true};
using integer =
    std::conditional<Use64BitIntegers,
                     std::int64_t,
                     std::int32_t>::type;

int main(void) 
{
  integer MyInt{42};
  std::cout << typeid(integer).name() << " ("
            << sizeof(integer) << " bytes)";
  return 0;
}