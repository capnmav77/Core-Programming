#include <functional>
#include <iostream>
int main(void)
{
    std::logical_and<int> la; // Argument type is int
    std::logical_or<> lo; // Argument type is void deduced
    std::logical_not<void> ln; //Argument type is void and deduced

    std::cout << la(10,0) << std::endl; // Logical AND operation of two integers. 
    std::cout << lo(10, 0) << std::endl; // Logical OR operation of two arguments, type deduction
    std::cout << ln(false) << std::endl; // Logical NOT operation of the argument, type deduction
    return 0;
}