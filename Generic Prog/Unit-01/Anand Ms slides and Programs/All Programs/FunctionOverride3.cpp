// C++ program to access overridden function using pointer
// of Base type that points to an object of Derived class
#include <iostream>
using namespace std;

class Parent {
public:
	int a=2;
	void PrintMesg()
	{
		cout << "Base Function" << endl;
	}
};

class Child : public Parent {
public:
	int a= 10;
	void PrintMesg()
	{
		cout << "Derived Function" << endl;
	}
	
};

int main()
{
	Child Child_Derived;
	Child_Derived.a = 0364;

	// pointer of Parent type that points to derived class object
	Parent* ptr = &Child_Derived;

	// call function of Base class using ptr
	ptr->PrintMesg(); // prints "Base Function" because it is calling the base class function i.e PrintMesg in the parent class or base class therefore it is not overridden

	// how this works 
	// the pointer of the base class is pointing to the object of the derived class
	// therefore the function of the base class is called and not the function of the derived class
	// this is because the function of the base class is not overridden by the function of the derived class
	// therefore the function of the base class is called

	cout<<ptr->a<<endl;

	return 0;
}
