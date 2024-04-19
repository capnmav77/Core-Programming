#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T =int , int count = 3>
T foo(T x){
    for(int i=0 ; i<count ; i++){
        x = x*x;
    }
    return x;
}


template<typename T>
bool equal(T a, T b){
    return a==b;
}

int main()
{
    // int x{2};
    // cout<<foo<>(x)<<endl;
    // cout<<x<<foo<int,2>(x)<<endl;
    // cout<<2.5<<foo<double,2>(2.5)<<endl;
    // int a[] = {1,2,3,4,5};
    // cout<<foo<int,5>(a[2])<<endl;

    cout<<equal(2,2)<<endl;
    char a[] = "abc";
    char *b = a;
    char c[] = "abc";

    cout<<a<<endl;
    cout<<b<<endl;

    cout<<equal(a,b)<<endl;
    cout<<equal(a,c)<<endl;

    return 0;
}