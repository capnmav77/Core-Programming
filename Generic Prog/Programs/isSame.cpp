// isSame.cpp

#include <iostream>
#include <type_traits>

namespace rgr {

  template<class T, T v>
  struct integral_constant {
      static constexpr T value = v;
      typedef T value_type;
      typedef integral_constant type;
      constexpr operator value_type() const noexcept { return value; }
      constexpr value_type operator()() const noexcept { return value; } //since c++14
  };

typedef integral_constant<bool, true> true_type;                      // (2)              
  typedef integral_constant<bool, false> false_type;
  
  template<class T, class U>
  struct is_same : false_type {};                                       // (3)
 
  template<class T>
  struct is_same<T, T> : true_type {};

}

int main() {

    std::cout << '\n';

    std::cout << std::boolalpha;

    std::cout << "rgr::is_same<int, const int>::value: " 
              << rgr::is_same<int, const int>::value << '\n';          // (1)
    std::cout << "rgr::is_same<int, volatile int>::value: " 
              << rgr::is_same<int, volatile int>::value << '\n';
    std::cout << "rgr::is_same<int, int>::value: "  
              << rgr::is_same<int, int>::value << '\n';

    std::cout << '\n';

    std::cout << "std::is_same<int, const int>::value: " 
              << std::is_same<int, const int>::value << '\n';
    std::cout << "std::is_same<int, volatile int>::value: " 
              << std::is_same<int, volatile int>::value << '\n';
    std::cout << "std::is_same<int, int>::value: "  
              << std::is_same<int, int>::value << '\n';

    std::cout << '\n';

}