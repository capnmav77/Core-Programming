#include<bits-stdc++.h>
#include<utility>
#include<iostream>
using namespace std;

template<typename T, typename U>
auto minimum(T&& a,U&& b)->decltype(a<b?a:b)
{
    return a<b ? a: b;
}

template<typename T, typename U>
decltype(auto) minimum(T&& a,U&& b)
{
    return a<b ? a: b;
}



template<typename T, typename U>
auto minimum(T&& a,U&& b)
{
    return a<b ? a: b;
}



template<typename T>
T const& func(T const& ref){
    return ref;
}


template<typename T>
auto func_caller(T&& ref){
    return func(std::forward<T>(ref));
}


int main(){

    return 0;
} 