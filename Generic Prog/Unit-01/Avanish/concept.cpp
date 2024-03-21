#include<iostream>
#include<concepts>

// template <std::integral T>
// T Average(T x,T y)
// {
//     std::cout<<"Average Integral Type"<<std::endl;
//     return (x+y)/2;
// }

template <typename T>
requires std::integral<T>
T Average(T x,T y)
{
    std::cout<<"Average Integral Type"<<std::endl;
    return (x+y)/2;
}


template <std::floating_point T>
T Average(T x,T y)
{
    std::cout<<"Average Floating type Type"<<std::endl;
    return (x+y)/2;
}

template <std::integral T>
class Container
{
    T Contents;
}



int main(void)
{
    Average(1,2);
    Average(1.5,2.2);
    Container<int> stuff;
    Container<float> moreStuff;
    return 0;
}