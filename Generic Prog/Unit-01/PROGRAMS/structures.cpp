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

class Example
{
    public: 
        int a;
        int *ptr;
        int b;
        Example(int x){
            a = x;
        }
        Example(Example &obj){
            cout<<"Copy constructor called"<<endl;
            a = obj.a;
        }
        //dynamic constructor
        Example(int n){
            this->ptr = new int[n];
        }

        //deligation constructor 
        Example(int n, int m):Example(n){
            this->b = m;
        }
};


int main()
{
    Example e1(10); // deep copy
    Example e2(e1); // deep copy
    Example e3(12); // dynamic constructor

    e3 = e2; //shallow copy
    cout<<e2.a;
    return 0;
}


// deep copy - when we copy the values of the data members of the object to another object
// shallow copy - when we copy the address of the data members of the object to another object but we can modify shallow copy by using operator overload
// copy constructor - constructor which is used to create a copy of an object