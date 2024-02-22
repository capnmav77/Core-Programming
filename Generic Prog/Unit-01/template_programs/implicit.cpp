#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T>
struct foo
{
    void f() { cout<<"foo<T>::f()"<<endl; };
    void g() {int a = "42";}
};

// int main()  leaving the syntax uhnchecked 
// {
//     foo<int> x;
//     x.f();
//     return 0;
// }


int main(){
    foo<int> x;
    foo<int> *p ;
    foo<double> *q; // we can generalize that pointers which are declared but not called can be left uninitialized  
    return 0;
}