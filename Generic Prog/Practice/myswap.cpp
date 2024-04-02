#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
void myswap(T* p , T* q){
    T temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int x{10}, y{20};
    myswap(&x,&y);
    cout<<x<<" "<<y;

    return 0;
}