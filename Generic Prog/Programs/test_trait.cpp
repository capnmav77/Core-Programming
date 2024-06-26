#include <type_traits>

int main() {

  std::enable_if_t<true, int> MyInt{42};
/*

  std::enable_if<false, int>::type MyInt{42};
*/
}
