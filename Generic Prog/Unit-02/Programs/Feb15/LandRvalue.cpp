#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    A(int &x){
        cout<<"lvalue reference"<<endl;
    }
    A(int &&x){
        cout<<"rvalue reference"<<endl;
    }
};



int main(){
    int x=10;
    A a1(x);
    A a2(20);

    return 0;
}