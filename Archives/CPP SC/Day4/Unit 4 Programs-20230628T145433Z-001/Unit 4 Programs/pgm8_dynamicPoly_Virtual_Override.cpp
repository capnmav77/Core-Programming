//dynamicPoly_Virtual_Override.cpp
//The pgm demonstrates dynamic polymorphism
//In C++, dynamic binding happens when a virtual function is called through a reference (or a pointer) to a base class.
//Virtual function defined in a derived class that has the same parameter list as a virtual in a base class overrides the base-class definition.
#include<iostream>

using namespace std;

class A
{
	int ma1;
	int ma2;
 public: 

	A(int a1,int a2){ma1=a1;ma2=a2;}
	virtual void display() {cout<<ma1<<" "<<ma2<<endl;}		//virtual function
};

class B:public A
{
	int mb1;
 public: int mb2;

	B(int b1,int b2,A a):A(a){mb1=b1;mb2=b2;}		
	void display(){A::display();cout<<mb1<<" "<<mb2<<endl;}		//A::display() is overridden
};

int main()
{
	A a(2,3);
	cout<<"Object a"<<endl;
	a.display();

	B b(4,5,a);				
	cout<<"Object b"<<endl;
	b.display();

	A* pA=&a;
	B* pB=&b;

	cout<<endl;
	cout<<"Object a via ptr"<<endl;
	pA->display();

	cout<<"Object b via ptr"<<endl;
	pB->display();

	A& rA=a;
	B& rB=b;

	cout<<endl;
	cout<<"Object a via reference"<<endl;
	rA.display();

	cout<<"Object b via reference"<<endl;
	rB.display();

//Below line is an error, because we are downcasting i.e., storing a base class object in a derived class pointer
//	pB=&a;

//Below line is OK, because we are upcasting i.e., storing a derived class object in a base class pointer
	pA=&b;

	cout<<endl;
	cout<<"Dynamic Polymorphism, pA holds derived class object, it calls B::display() ";
	cout<<"because display() is virtual in base class, binding happens at run time. ";
	cout<<"Function is called depending on the object held by pointer at run time"<<endl;
	pA->display();		//calls B::display(), because dynamic binding happens

//Below line is an error, because we are downcasting i.e., storing a base class object in a derived class reference
//	rB=a;


//Below line is OK, because we are upcasting i.e., storing a derived class object in a base class pointer
	A& refA=b;

	cout<<endl;
	cout<<"Dynamic Polymorphism, refA holds derived class object, it calls B::display() ";
	cout<<"because display() is virtual in base class, binding happens at run time. ";
	cout<<"Function is called depending on the object held by reference at runtime"<<endl;
	refA.display();		//calls B::display(), because dynamic binding happens

	return 0;
}

/*
Output:
Object a
2 3
Object b
2 3
4 5

Object a via ptr
2 3
Object b via ptr
2 3
4 5

Object a via reference
2 3
Object b via reference
2 3
4 5

Dynamic Polymorphism, pA holds derived class object, it calls B::display() because display() is virtual in base class, binding happens at run time. Function is called depending on the object held by pointer at run time
2 3
4 5

Dynamic Polymorphism, refA holds derived class object, it calls B::display() because display() is virtual in base class, binding happens at run time. Function is called depending on the object held by reference at runtime
2 3
4 5
*/
