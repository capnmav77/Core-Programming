//protected.cpp
//Demonstrates the accessibility of different data members in derived class when publicly derived
//Protected members are accessible only in its own class and its child class

#include<iostream>

using namespace std;

class B
{
	int b1;
	public : int b2;
		B(int=0,int=0,int=0);
		void showB(){cout<<"B::"<<b1<<" "<<b2<<" "<<b3<<endl;}
	protected: int b3;
};
B::B(int p,int q,int r)
{
	b1=p;
	b2=q;
	b3=r;
}
class D: public B
{
	//b1(inherited) is not accessible directly in D. Because it is private in B.
	//b2(inherited) accessible in D. Because it is public in B.
	//b3(inherited) accessible in D. Because it is protected in B.
	int d1;
	public: int d2;
	
	D(int p,int q,int r,int s,int t):B(p,q,r){d1=s; d2=t;}

	void showD()
	{
		cout<<"Base class instance of D is ";
		B::showB(); 
		cout<<"Specific members of D are ";
		cout<<"D::"<<d1<<" "<<d2<<endl;
	}

	void showProtectedB()
	{
		cout<<"To show, protected members of base class are accessible in derived class"<<endl;		
		cout<<"I'm protected member of base class B::b3, accessed in derived class D:"<<b3<<endl;
	}
};


int main()
{
	B b(1,2,3);
	D d(10,20,30,40,50);
//b1 and d1 are not accessible because they are private members
//b3 is not accessible because it is protected member
//	cout<<b.b1<<endl;
//	cout<<b.b2<<endl;	//accessible, because public in B
//	cout<<b.b3<<endl;
//	cout<<d.d1<<endl;
//	cout<<d.d2<<endl;	//accessible, because public in D
//	cout<<d.b1<<endl;
//	cout<<d.b2<<endl;	//accessible, because public in D
//	cout<<d.b3<<endl;

	cout<<"I'm object B"<<endl;
	b.showB();
	cout<<endl<<"I'm object D"<<endl;
	d.showD();

	cout<<endl;
	d.showProtectedB();

	return 0;
}

/*
Output:
I'm object B
B::1 2 3

I'm object D
Base class instance of D is B::10 20 30
Specific members of D are D::40 50

To show, protected members of base class are accessible in derived class
I'm protected member of base class B::b3, accessed in derived class D:30
*/
