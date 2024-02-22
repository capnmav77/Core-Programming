// C++ program to illustrate the abstract class with pure
// virtual functions
#include <iostream>
using namespace std;

class Test {
	// private member variable
	int x;

public:
	// pure virtual function
	virtual void show() = 0;

	// getter function to access x
	int getX() { return x; }
};

int main(void)
{
	// Error: Cannot instantiate an abstract class
	Test t;

	return 0;
}
