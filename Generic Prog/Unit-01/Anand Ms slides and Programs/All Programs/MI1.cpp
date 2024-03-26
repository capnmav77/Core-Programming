#include<iostream>
using namespace std;

class A
{
public:
    int x;
    A() { cout << "A's constructor called" << endl; }
};

class B
{
    public:
    int x;
    B() { cout << "B's constructor called" << endl; }
};

class C: public B, public A // Note the order
{
    public:
    C() { cout << "C's constructor called" << endl; }
};

int main()
{
	C c;
    c.x = 9;
	return 0;
}
