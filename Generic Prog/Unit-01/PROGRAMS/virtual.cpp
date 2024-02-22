#include<bits/stdc++.h>

using namespace std;


class base{
    public:
        virtual void print(){
            cout<<"print Base class"<<endl;
        }

        void show(){
            cout<<"show dervied class"<<endl;  
        }
};

class derived:public base{
    public:
        void print(){
            cout<<"print Derived class"<<endl;
        }

        void sshow(){
            cout<<"show dervied class"<<endl;  
        }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;

    //virtual function, binded at runtime  
    bptr->print();

    // Non-virtual function, binded at compile time
    bptr->show();

    return 0;
}