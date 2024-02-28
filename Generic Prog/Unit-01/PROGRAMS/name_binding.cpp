#include<iostream>
template<typename T>
struct parser;
void handle(double value)
{
    std::cout<<"Processing a double: " << value << std::endl;
}


template<typename T>
struct parser{
    void parse()
    {
        handle(42);
    }
};
void handle(int value)
{
    std::cout<<"Processing a double: " << value << std::endl;
}
