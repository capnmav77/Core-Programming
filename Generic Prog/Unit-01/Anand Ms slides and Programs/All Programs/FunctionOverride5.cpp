// C++ Program Demonstrating
// Accessing of Overridden Function
#include <iostream>
using namespace std;

// defining of the Parent class
class Parent

{

public:
	// defining the overridden function
	void Print_Mesg ()
	{
		cout << "I am the Parent class function" << endl;
	}
};

// defining of the derived class
class Child : public Parent

{
public:
	// defining of the overriding function
	void Print_Mesg()
	{
		cout << "I am the Child class function" << endl;
	}
};

int main()
{
	// create instances of the derived class
	Child chld1, chld2;

	// call the overriding function
	chld1.Print_Mesg ();

	// call the overridden function of the Base class
	chld2.Parent::Print_Mesg ();
	return 0;
}
