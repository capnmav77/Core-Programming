#include<iostream>
#include<bits/stdc++.h>
//using namespace std;

template<typename... T>
int sum(T... args){
    std::cout<<"sizeof...(args) = "<<sizeof...(args)<<std::endl;
    // cout<<...+ args<<endl; //error: expected primary-expression before '...' token
    return (... + args);
}

// variadic variable templates
template < typename... T>  
int foo(int a , T... args){
    return (a + ... + args);
}

template<typename... Args>
using int_foo = foo<int,Args...>; //error: expected unqualified-id before '...' token

int main()
{
    //std::cout<<sum(1,2,3,4,5.0,'a',6,7,8,9,10.0)<<std::endl;
    std::cout<<int_foo(1,2,3,4,5,6,7,8,9,10)<<std::endl;
    return 0;
}