#include <type_traits>
#include <iostream>

using std::enable_if, std::is_class;
template <typename T, enable_if<is_class<T>::value, int>::type = 0>
void Function(T Arg) {
  std::cout << "That was a class\n";
}

template <typename T,
          enable_if_t<!is_class_v<T>, int> = 0>
void Function(T Arg) {
  // std::cout << "That wasn't\n";
}

class Character {};

int main() {
  Function(Character{});
  Function(3.14);
}
