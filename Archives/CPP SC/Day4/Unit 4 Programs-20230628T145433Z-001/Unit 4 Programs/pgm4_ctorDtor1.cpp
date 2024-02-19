//ctorDtor1.cpp
//This program demonstrates the order in which ctor and dtor are called
#include<iostream>
using namespace std;

class B
{
	int m_b;
 public:
	B(int);
	void show();
	~B();
};

B::B(int b)
{
	cout<<"Base class ctor"<<this<<endl;	
	m_b=b;
}

void B::show()
{
	cout<<"Base class data="<<m_b<<endl;
}

B::~B()
{
	cout<<"Base class dtor"<<this<<endl;
}

class D:public B
{
	int m_d;
 public:
	D(int,int);
	void show();
	~D();	
};

D::D(int b,int d):B(b)
{
	cout<<"Derived class ctor"<<this<<endl;	
	m_d=d;
}

void D::show()
{
	B::show();
	cout<<"Derived class data="<<m_d<<endl;
}

D::~D()
{
	cout<<"Derived class dtor"<<this<<endl;
}

int main()
{
	B b(10);
	b.show();
	D d(20,30);
	d.show();
	return 0;
}

/*
Output:
Base class ctor0x7ffc6379df10
Base class data=10
Base class ctor0x7ffc6379df20
Derived class ctor0x7ffc6379df20
Base class data=20
Derived class data=30
Derived class dtor0x7ffc6379df20
Base class dtor0x7ffc6379df20
Base class dtor0x7ffc6379df10
*/
