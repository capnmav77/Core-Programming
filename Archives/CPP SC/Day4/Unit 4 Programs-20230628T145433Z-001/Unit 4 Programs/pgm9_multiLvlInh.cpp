//multiLvlInh.cpp
//Pgm demonstrates multi level inheritance and dynamic polymorphism
//Once a function is defined virtual, it remains virtual down the inheritance hierarchy

#include<iostream>

using namespace std;


class A
{
	int m_a1,m_a2;
 public: A(int a1,int a2)
	{
		m_a1=a1;
		m_a2=a2;
	}
	virtual void display(){cout<<"Base"<<endl;cout<<m_a1<<" "<<m_a2<<endl;}
};

class B:public A
{
	int m_b1;

 public:
	B(int a1,int a2,int b1):A(a1,a2)
	{
		m_b1=b1;
	}
	void display(){					//display() is overridden
		A::display();
		cout<<"Derived"<<endl;cout<<m_b1<<endl;
	}
};

class C:public B
{
	public:C(int a1,int a2,int a3):B(a1,a2,a3){}
	//display is inherited, and not overridden here
};


int main()
{
	A a(2,3);
	B b(4,5,6);
	C c(7,8,9);


	B* pB=&c;
	pB->display();		//Base class pointer holding derived class object c. Calls the inherited display() in class C

	cout<<endl;
	A* pA=&b;
	pA->display();		//Base class pointer holding derived class object b. Calls the overridden display() in class B

	return 0;
}	

/*
Output:
Base
7 8
Derived
9

Base
4 5
Derived
6
*/
