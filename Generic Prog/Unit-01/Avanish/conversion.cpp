#include<iostream>
#include<bits/stdc++.h>


using namespace std;


class Time{
    int hrs,mins;

    public:
        Time()
        {
            hrs=0;
            mins=0;
        }

        Time(int hr,int min){
            hrs = hr;
            mins = min;
        }

        Time(int x)
        {
            hrs=x/60;
            mins=x%60;
        }

        operator int(){
                return hrs*60 + mins;
        }

        ~Time(){}

        void display()
        {
            cout<<hrs<<":"<<mins<<endl;
        }
};



int main()
{
    Time t ;
    int dur =122;

    t = dur;

    t.display();

    int a =  t;
    cout<<a<<endl;

}