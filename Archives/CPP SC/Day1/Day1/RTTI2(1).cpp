// C++ program to demonstrate
// Run Time Type Identification successfully
// With virtual function

#include <iostream>
using namespace std;

// Initialization of base class
class B {
	virtual void fun() {}
};

// Initialization of Derived class
class D : public B {
};

// Driver Code
int main()
{
	B* b = new D; // Base class pointer
	D* d = dynamic_cast<D*>(b); // Derived class pointer
	if (d != NULL)
		cout << "works";
	else
		cout << "cannot cast B* to D*";
	getchar();
	return 0;
}
