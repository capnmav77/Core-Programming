#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename R1 , typename...A1 , typename R2 , typename...A2>
struct func_pair<R1(A1...),R2(A2...)>{ //initializing the template with the function signature
    std::function<R1(A1...)> f1;
    std::function<R2(A2...)> f2;
};

bool twice_as(int x , int y){
    return x*2 == y;
}

double sum_and_divide(int x , double y){
    return x/y ;
}

int main(){
    func_pair<bool(int,int),double(int,double)> p;
    p.f1 = twice_as;
    p.f2 = sum_and_divide;

    return 0;
}