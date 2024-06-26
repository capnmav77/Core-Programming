#include <functional>
#include <iostream>

int main(void)
{
    std::bit_and<int> ba; // Argument type is int
    std::bit_or<> bo; // Argument type is void
    std::bit_xor<void> bx; //Argument type is void
    std::bit_not<char> bn; //Argument type is void

    std::cout << ba(0x11,0x22) << std::endl; // Bitwiae AND operation of two integers. 
    std::cout << bo(0x11,0x22) << std::endl; // Bitwise OR operation of two arguments of deduced types
    std::cout << bn(~('A')) << std::endl; // Bit-wise NOT operation of the argument type char
    std::cout << bx(0x10,0x01) << std::endl; // Bit-wise XOR operation of the argument of deduced
    return 0;
}