#include<iostream>
#include<bits/stdc++.h>
using namespace std;


constexpr double PI = 3.14159265358979323846;


template <typename T>
T sphere_volume(T const r)
{
    return (4.0 / 3.0) * PI * r*r*r;
}

int main()
{
    cout<<sphere_volume(5.0f)<<endl; // when we use it as double it wont' give an error , but when we use it as float it does.
    return 0;
}

// this is because of precision error.
// double value of pi does not fit in a float
// so we need to use float value of pi