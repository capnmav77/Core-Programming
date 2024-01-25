#include<iostream>
#include<bits/stdc++.h>


using namespace std;


class base{
    public:
        virtual void print()
        {
            cout<<"Print base class\n";
        }

        void show()
        {
            cout<<"Show base class\n";
        }
}

class derived : public base{
    public:
        void show(){
            cout<<"Show derived class\n";
        }

        void print()
        {
            cout<<"Print deroved class\n";
        }
};

int main()
{
    base* bptr;
    derived d;
    bptr = &d;

    //virtual function binding at the 
    bptr->print();


    bptr->show();
}