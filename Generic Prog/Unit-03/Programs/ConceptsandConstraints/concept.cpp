#include<iostream>
#include<bits/stdc++.h>
#include<concepts>

using namespace std ;

//concept has bought in a word called integral -> which is a concept in c++20
//here integral is a concept which is a type of integer that is a subset of integer

template<std::integral T>
class container
{
    T contents;
};



//another keyword is called requires 
//requires is used to specify the constraints on the template parameters
template<typename T>
requires std::floating_point<T> || std::integral<T>
T average(T a, T b){
    return (a+b)/2;
}


class player{}
class Monster {} 
class Goblin : public Monster {}

template <typename T> 
    requires std::is_base_of_v<player,T> || std::is_base_of_v<Monster,T>
void attack(T &t){
    cout<<"Attacking"<<endl;
}



int main(){
    container<int> stuff;
    container<float> morestuff;
    return 0; 
}