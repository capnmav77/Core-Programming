//datamembers.cpp
//This program demonstrates the accessibility of base class and derived class data members
#include<iostream>

using namespace std;

class B
{
	int mb1;
 public :
	int mb2;
	B(int b1=0,int b2=0)		//ctor of B with default parameters
	{
		mb1=b1;
		mb2=b2;
	}
	

};

class D: public B		//D derives from B in public mode
{
	int md1;
 public: 
	int md2;
	D(int b1=0,int b2=0,int d1=0,int d2=0):B(b1,b2)	//ctor of D with default parameters, explicitly calls base class ctor
	{
		md1=d1;
		md2=d2;
	}

};


int main()
{
	B b;
	D d;

//	cout<<b.mb1<<endl;		//B:mb1 is not accessible to Derived class D, as well as main because mb1 is private
	cout<<b.mb2<<endl;
//	cout<<d.md1<<endl;		//D:md1 is not accessible to main, because md1 is private
	cout<<d.md2<<endl;
//	cout<<d.mb1<<endl;		//B:mb1 is not accessible to Derived class D, as well as main because mb1 is private
	cout<<d.mb2<<endl;

	return 0;
}

/*
Output:
0
0
0
*/
