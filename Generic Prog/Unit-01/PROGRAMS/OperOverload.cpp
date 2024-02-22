#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Count
{
    int val;
    Count()
    {
        int val= 0;
    }

    //prefix
    Count operator++()
    {
        ++val;
    }

    //postfix
    Count operator++(int)
    {
        val++;
    }
    int get(){
        return val;
    }
};

class Largest
{
    int size;
    public: 
    Largest()
    {
        size = 0;
    }
};


int main()
{
    Count c;
    cout<<c.get()<<endl;
    c++;
    cout<<c.get()<<endl;
    
    return 0;
}