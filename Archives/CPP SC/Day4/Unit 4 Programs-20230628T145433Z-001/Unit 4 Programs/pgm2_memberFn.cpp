//memberFn.cpp
//This program demonstrates that all member functions of base class are inherited in derived class
#include<iostream>

using namespace std;

class B
{
	public:	void x(){cout<<"I'm x of B"<<endl;}
		void y(){cout<<"I'm y of B"<<endl;}

};

class D: public B
{
	//inherits x() and y() of B
	//adds new z() in D
	public: void z(){cout<<"I'm new to D, not inherited from B"<<endl;}
};


int main()
{
	B b;
	D d;
	
	b.x();
	b.y();

	d.x();		//calls the inherited x
	d.y();		//calls the inherited y
	d.z();		//calls z

	return 0;
}
/*
Output:
I'm x of B
I'm y of B
I'm x of B
I'm y of B
I'm new to D, not inherited from B
*/
