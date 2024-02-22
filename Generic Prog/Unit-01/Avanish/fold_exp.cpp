#include<iostream>


template<typename...T>
int sum(T...args)
{
    return (...+args);
}



int main()
{
    std::cout<<sum(1,2,3,4,5,6,7,8)<<std::endl;
}