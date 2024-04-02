#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T> 

struct What{
    public:
    What(T n):x(n),p(new T[n]){}
    private: 
    T *p; //pointer to an array of T
    T x;
};

//move assignment operator
template<typename T>
What<T>& operator = (What<T>&& w){ //&& represents an rvalue reference
    if(this != &w){ // & is the address of the object 
        delete[] p;
        p = w.p;
        w.p = nullptr;
    }
    return *this;
}



int main()
{
    //move assignment operator
    What<int> w(10);
    What<double> w2(20.0);

    //move constructor
    What<int> w3 = w;


    return 0;
}