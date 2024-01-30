#include<iostream>

using namespace std;

template <typename T>
struct foo{
    void f(){}
    void g(){
        int x="200";
    }
};

int main()
{
    foo<int>* x;
    foo<int> y;
    foo<double>* q;
    q->f();
}