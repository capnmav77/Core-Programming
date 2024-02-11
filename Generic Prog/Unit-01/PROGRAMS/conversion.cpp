#include<bits/stdc++.h>

using namespace std;

class Time{
    int hrs , mins;
    public: 
        Time() //Default constructor
        {
            hrs = 0;
            mins = 0;
        }
        //Constructor with specified values 
        Time(int hr , int min)
        {
            hrs = hr;
            mins = min;
        }
        //operator int() is a conversion operator
        operator int(){
            return hrs*60 + mins;
        }
        operator float(){
            return hrs + mins/60.0;
        }
        //Destructor
        ~Time()
        {
            cout<<"Destructor called"<<endl;
        }
};


int main()
{
    Time t(1,60);
    int x = t;
    float y = t;
    cout<<x<<endl;
    cout<<y<<endl;

    return 0;
}