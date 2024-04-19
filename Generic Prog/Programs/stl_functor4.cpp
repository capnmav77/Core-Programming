#include <functional>
#include <iostream>
struct Money
{
    int Doller;
    int Cent;
    Money& operator-()
    {
        Doller = -Doller;
        Cent = -Cent;
        return *this;
    }
};
int main(void)
{
    std::cout << std::negate<double>()(10.7) << '\n'; 
    // Explicit type as the template argument
    std::cout << std::negate<void>()(100.7) << '\n'; 
    // template specialization used, type is auto deduced from the arguments
    Money m{ 5,40 };
    m = -m;
    std::cout << m.Doller << " Doller " << m.Cent << " Cent" << '\n'; 
    // Default template argument is void
    return 0;
}