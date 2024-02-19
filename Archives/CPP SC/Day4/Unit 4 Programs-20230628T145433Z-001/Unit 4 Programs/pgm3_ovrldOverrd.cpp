//ovrldOverrd.cpp
//This program demonstrates overloading and overriding of methods in derived class
#include<iostream>

using namespace std;

class B
{
	public:	void x(){cout<<"I'm x of B"<<endl;}
		void y(){cout<<"I'm y of B"<<endl;}

};

class D: public B
{
	public:	void x(){cout<<"I'm Overridden x of D"<<endl;}			//Overrides B's x()
		void y(int a){cout<<"I'm Overloaded y of D"<<", a="<<a<<endl;}	//Overloads B's y()
		void z(){cout<<"I'm new to D, not inherited from B"<<endl;}
		
};


int main()
{
	B b;
	D d;
	
	b.x();
	b.y();

	d.x();				//static polymorphism
	d.y(2);				//static polymorphism
	d.z();

	return 0;
}

/*
Output:
I'm x of B
I'm y of B
I'm Overridden x of D
I'm Overloaded y of D, a=2
I'm new to D, not inherited from B
*/
