#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T>
struct foo
{
    static T data; // in regular class , the static member is attached to a type of the template , i.e a single copy is shared among all the similar templated type . 
};

template <typename T>
T foo<T>::data = 0; 


int main()
{
    foo<int> a; 
    foo<double> b;
    foo<double> c; 
    foo<int> d;
    std::cout<<a.data<<'\n';
    std::cout<<b.data<<'\n';
    std::cout<<c.data<<'\n';

    b.data = 42; 
    a.data = 12;
    std::cout<<a.data<<'\n';
    std::cout<<b.data<<'\n';
    std::cout<<c.data<<'\n';
    std::cout<<d.data<<'\n';

    return 0;
}