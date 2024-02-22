// C++ program to access overridden function
// in main() using the scope resolution operator ::

#include <iostream>
using namespace std;

class Parent {
public:
	void PrintMesg()
	{
		cout << "Base Function" << endl;
	}
};

class Child : public Parent {
public:
	void PrintMesg()
	{
		cout << "Derived Function" << endl;
	}
};

int main()
{
	Child Child_Derived;
	Child_Derived.PrintMesg();

	// access PrintMesg() function of the Base class
	Child_Derived.Parent::PrintMesg();
	return 0;
}
