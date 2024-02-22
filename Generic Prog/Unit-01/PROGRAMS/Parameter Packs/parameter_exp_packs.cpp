#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<class...I>
void func(I...args){
    for(auto i: {args...}){
        cout<<i<<endl;
    }
}



int main()
{
    func("Hello","World","How","are","you?",1,2,3,4,5,6);
    return 0;
}