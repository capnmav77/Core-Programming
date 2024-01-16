#include<iostream>
#include<bits/stdc++.h>


using namespace std;


class A{
    int a,b,c;
    A()
    {
        a=10;
        b=20;
    }
    public:
     A(int z) : A()
     {
        c=z;
     }

     void display()
     {
        cout<<a<<" "<<b<<" "<<c<<endl;
     }

     ~A()
     {

     }

     //Initializer list
     A(int i=0,int j = 0):a(i),b(j){}
};

int main()
{
    A a=A(20);

    a.display();

}