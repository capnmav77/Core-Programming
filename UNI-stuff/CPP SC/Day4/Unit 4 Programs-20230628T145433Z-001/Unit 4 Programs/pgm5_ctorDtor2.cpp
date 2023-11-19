//ctorDtor2.cpp
//This program Demonstrates the order in which ctor and dtor are called
//This program also Demonstrates multi level inheritance
//Constructors are invoked in the order of inheritance. i.e., 
//(a) base class constructor
//(b) member objects constructor (if any)
//(c) derived class constructor is invoked
#include<iostream>
using namespace std;

class A
{
 public:
	A(){ cout<<"A class ctor"<<endl; }
	~A(){ cout<<"A class dtor"<<endl; }
};

class B:public A
{
 public:
	B(){ cout<<"B class ctor"<<endl; }
	~B(){ 	cout<<"B class dtor"<<endl; }	
};

class C:public B
{
	B bObj;		//bObj is an object of class B, so first A class ctor is invoked then B class ctor 

 public:
	C(){ cout<<"C class ctor"<<endl; }
	~C(){ cout<<"C class dtor"<<endl; }	
};

int main()
{
	C c;
	
	return 0;
}

/*
Output:
A class ctor
B class ctor
A class ctor
B class ctor
C class ctor
C class dtor
B class dtor
A class dtor
B class dtor
A class dtor
*/
