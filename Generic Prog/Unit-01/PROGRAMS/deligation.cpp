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

class A{
    int a,b,c;
    A(){
        a=10;
        b=20;
        c=30;
    }


    public:
        A(int c) :A() // deligation constructor , we tell the compiler to run A first and then run A here
        {
            this->c = c; //only update c
        }

        ~A(){
            cout<<"Destructor called"<<endl; // called when the object goes out of scope
        }

        // ~A(int c){ // destructor overloading even though it cannot have parameters
        //     cout<<"Destructor called"<<endl;
        // }

        void show(){
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        // initializer List
        A(int a , int b):a(a),b(b),c(10){ // this is called initializer list which is used to initialize the data members of the class a = a and b = b
            // this->a = a;
            // this->b = b;
        }
};


int main()
{

    A a = A(50);
    a.show();
    return 0;
}

