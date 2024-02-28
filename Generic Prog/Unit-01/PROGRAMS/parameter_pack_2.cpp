#include<iostream>

using namespace std;


struct a1{};
struct a2{};
struct a3{};
struct a4{};
struct a5{};


template<class...X> struct baseC{};
template<class...A1> struct container{};
template<class...A,class...B,class...C>
struct container<baseC<A,B,C...>...>:public baseC<A...>{};

int main()
{
    container <baseC<a1,a4,a5,a5,a5>,baseC<a3,a2,a5,a5,a5>,baseC<a2,a3,a5,a5,a5>,baseC<a4,a1,a5,a5,a5>> test;
}