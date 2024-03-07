// C++ program to demonstrate function overriding

#include <iostream>
using namespace std;

class Parent {
	int a;
public:
	void My_Print()
	{
		cout << "Base Function" << endl;
	}

	void set(int b){
		a=b;
	}

	int get()
	{
		return a;
	}
};

class Child : public Parent {
public:
	void My_Print()
	{
		cout << "Derived Function" << endl;
		Parent::My_Print();

		Parent::set(100);

		cout<<Parent::get()<<endl;
	}
};

int main()
{
	Child Child_Derived;
	Child_Derived.My_Print(); // prints "Derived Function" because it is overriding the base class function i.e My_Print in the parent class or base class


	cout<<Child_Derived.Parent::get()<<" "<<endl;	
	
	return 0;
}
