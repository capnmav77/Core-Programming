#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//decltype is used to deduce the type of an expression at compile time

//example
template<typename T>
T const& func(T const& ref){
    return ref;
}

template <typename T>
T const&& func(T const&& ref){
    return ref;
}

template<typename T>
auto func_caller(T && ref){
    return func(std::forward<T>(ref)); //performs perfect forwarding -> T&& it forwards a lvalue reference 
}

//decltype is used to deduce the type of an expression at compile time



int main(){

    int x = 10;
    cout<<func_caller(10)<<endl; //10
    decltype(func_caller(10)) y = 10; //int y = 10;
    return 0;
}