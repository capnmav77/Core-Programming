#include<iostream>
#include<bits/stdc++.h>
using namespace std;



template <typename T>
constexpr T PI = T(3.14159265358979323846);


struct math_constants
{
    template<class T> //better because it can be specific to a certain type
    static constexpr T PI = T(3.14159265358979323846);

};

template <typename T>
T sphere_volume(T const r)
{
    return (4.0 / 3.0) * PI<T>*r*r*r;
}

// we can also initialzie the constexpr later on because it is a template and only the blurprint get's created first. 

int main()
{
    cout<<sphere_volume(5.0f)<<endl; // when we use it as double it wont' give an error , but when we use it as float it does.
    return 0;
}


