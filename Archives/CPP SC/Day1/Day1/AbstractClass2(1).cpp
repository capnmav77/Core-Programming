// C++ program that demonstrate that we can have pointers and references
// of abstract class type.

#include <iostream>
using namespace std;

class Base {
public:
	// pure virtual function
	virtual void show() = 0;
};

class Derived : public Base {
public:
	// implementation of the pure virtual function
	void show() { cout << "In Derived \n"; }
};

int main()
{
	// creating a pointer of type Base pointing to an object
	// of type Derived
	Base* bp = new Derived();

	// calling the show() function using the pointer
	bp->show();

	return 0;
}
