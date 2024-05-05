#include <functional>
#include <iostream>
struct Money
{
    int Doller;
    int Cent;
    Money& operator*(int m)
    {
        int d = (Cent*m) / 100;
        Cent = (Cent*m) % 100;
        Doller *= m;
        Doller += d;
        return *this;
        
    }

};

int main(void)
{
    std::cout << std::multiplies<int>()(5,10) << '\n'; //output : 50
    // Explicit type as the template argument
    std::cout << std::multiplies<void>()(5, 100) << '\n'; //output : 500
    // template specialization used, type is auto deduced from the arguments
    Money m{3, 40};
    m=std::multiplies<>()(m, 4);
    std::cout << m.Doller <<" Doller "<<m.Cent<<" Cent" << '\n'; 
    // Default template argument is void
    return 0;
}