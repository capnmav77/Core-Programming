#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>

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
    
    return 0;
}