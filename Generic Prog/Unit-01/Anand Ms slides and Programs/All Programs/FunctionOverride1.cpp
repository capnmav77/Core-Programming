// C++ program to demonstrate function overriding

#include <iostream>
using namespace std;

class Parent {
public:
	void My_Print()
	{
		cout << "Base Function" << endl;
	}
};

class Child : public Parent {
public:
	void My_Print()
	{
		cout << "Derived Function" << endl;
	}
};

int main()
{
	Child Child_Derived;
	Child_Derived.My_Print(); // prints "Derived Function" because it is overriding the base class function i.e My_Print in the parent class or base class
	return 0;
}
