//upCast_StaticPoly.cpp
//pgm demonstrates the different ways to access data members and member functions of a class
//1)via object 2)via pointer 3)via reference
//The pgm also demonstrates static polymorphism (none of the member functions are virtual)

#include<iostream>

using namespace std;

class A
{
	int ma1;
	int ma2;
 public: 

	A(int a1,int a2){ma1=a1;ma2=a2;}
	void display(){cout<<ma1<<" "<<ma2<<endl;}
};

class B:public A
{
	int mb1;
 public: int mb2;

	B(int a1,int a2,int b1,int b2):A(a1,a2){mb1=b1;mb2=b2;}		
	void display(){A::display();cout<<mb1<<" "<<mb2<<endl;}
};

int main()
{
	A a(2,3);
	cout<<"Object a"<<endl;
	a.display();

	B b(4,5,6,7);				
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
	cout<<"Static Polymorphism, even though pA holds derived class object, it calls A::display() ";
	cout<<"because display() is not virtual in base class. ";
	cout<<"Binding happens at compile time, function is called based on pointer type"<<endl;
	pA->display();		//calls A::display(), because static binding happens

//Below line is an error, because we are downcasting i.e., storing a base class object in a derived class reference
//	rB=a;


//Below line is OK, because we are upcasting i.e., storing a derived class object in a base class pointer
	A& refA=b;

	cout<<endl;
	cout<<"Static Polymorphism, even though refA holds derived class object, it calls A::display() ";
	cout<<"because display() is not virtual in base class. ";
	cout<<"Binding happens at compile time, function is called based on reference type"<<endl;
	refA.display();		//calls A::display(), because static binding happens

	return 0;
}

/*
Output:
Object a
2 3
Object b
4 5
6 7

Object a via ptr
2 3
Object b via ptr
4 5
6 7

Object a via reference
2 3
Object b via reference
4 5
6 7

Static Polymorphism, even though pA holds derived class object, it calls A::display() because display() is not virtual in base class. Binding happens at compile time, function is called based on pointer type
4 5

Static Polymorphism, even though refA holds derived class object, it calls A::display() because display() is not virtual in base class. Binding happens at compile time, function is called based on reference type
4 5
*/
