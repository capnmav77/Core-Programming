#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Count{
    int val;

    public:
        Count()
        {
            val = 0;
        }

        //prefix
        void operator ++ (){
            ++val;
        }

        //postfix
        void operator ++(int){
            val++;
        }

        int get()
        {
            return val;
        }
};

class Arr{
    int size;
    vector<int> v;

    public:
        Arr(int s)
        {
            size = s;
            v.resize(s);
        }
                                                                                                                                                        
};

class Larget
{
    int a,b,m;
    public:
        void set_data();
        friend find_max(Larget);
}

void Larget::set_data()
{

}



int main()
{
    Count a=Count();
    ++a;
    cout<<a.get()<<endl;
}