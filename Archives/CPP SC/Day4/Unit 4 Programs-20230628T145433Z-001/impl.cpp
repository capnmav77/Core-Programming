#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;


class A{
    int x;
    public:
        int y;
        A(int x,int y){
            x=x;
            y=y;
        }
        virtual int add(int a,int b){
            return a+b;
        }
        ~A();
};

class B: public A{
    int a;
    public:
        B(int a){
            a = a;
            A(1,2);
            a = add(9,3);
        }

        ~B();
};

int main()
{
    
    return 0;
}
