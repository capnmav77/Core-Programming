#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct math_constants
{
    template<class T> //better because it can be specific to a certain type
    static constexpr T PI = T(3.14159265358979323846);

};


// template <typename T>
// T add = [](T arg1 , T arg2)
// {
//     //define generalized lambda
//     return arg1 + arg2;
// };


int main()
{
    auto add = []<typename T>(T arg1 , T arg2)
    {
        //define generalized lambda
        return arg1 + arg2;
    };
    cout<<"sum of integers"<<add(5,6)<<endl;
    cout<<"sum of floats"<<add(5.5,6.6)<<endl;
    cout<<"concatenate strings"<<add(string("hello"),string("world"))<<endl;
    return 0;
}