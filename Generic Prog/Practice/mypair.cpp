#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//initializer list 

template<typename T1 , typename T2>
struct mypair{
    public: 
    mypair(T1 x , T2 y);
    void print(){
        cout<<first<<" "<<second;
    }
    private: 
    T1 first;
    T2 second;
};
 
//ctor for the above is 
template<typename T1 , typename T2>
mypair<T1,T2>::mypair(T1 x , T2 y):first{x},second{y}{}
// where T1 and T2 are the template parameters and x and y are the arguments passed to the ctor
//:first{x} is the member initializer list for the first member of the class and similarly for the second member
// ":" is the member initializer list which is used to initialize the members of the class

int main()
{
    mypair helo = mypair<int , double>(10,20.5);
    helo.print();
    return 0;
}