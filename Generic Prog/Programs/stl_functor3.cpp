#include <functional>
#include <iostream>
int main(void)
{
    std::cout << std::modulus<int>()(10,7) << '\n'; 
    // Explicit type as the template argument
    std::cout << std::modulus<void>()(100, 7) << '\n'; 
    // template specialization used, type is auto deduced from the arguments
    std::cout << std::modulus<>()(100, 7) << '\n'; 
    // template default argument is used, type is auto deduced from the arguments
    return 0;
    
}