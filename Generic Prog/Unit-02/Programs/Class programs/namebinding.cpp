#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
//struct parser;
struct handler
{
    void handle(T value)
    {
        cout<<"T value = "<<value<<endl;
    }
};

template <typename T>
struct parser{
    void parse(T arg)
    {
        arg.handle(42);
    }
};

template<>
struct handler<int>
{
    void handle(int value)
    {
        cout<<"int value = "<<value<<endl;
    }
};

int main()
{
    parser<int> p;
    //handler <int> h;
    p.parse();
    return 0;
}