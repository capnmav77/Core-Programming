#include<iostream>
#include<concepts>

// template <std::integral T>
// T Average(T x,T y)
// {
//     std::cout<<"Average Integral Type"<<std::endl;
//     return (x+y)/2;
// }

template <typename T>
concept MyConcept = std::integral<T> || std::floating_point<T>;



template <MyConcept T>
void myFunction(T t) {
    // Add your function implementation here
    // For example:
    // t.doSomething();
}



class Player{};
class Monster{};
class Goblin :public Monster{};

template <typename T>
requires std::is_base_of_v<Player, T> ||  std:is_base_of_v<Monster,T>
void func(T character)
{

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
    func(Goblin{});
    return 0;
}