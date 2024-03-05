#include <iostream>
#include <vector>

using namespace std;	

class A
{
public:
	int *ptr;
	A ()
	{
		ptr = new int;
		cout << "Constructor" << endl;
	}
	~A ()
	{
		cout << "Destructor" << endl;
		delete ptr;
	}
	A (const A &a1)   // Copy constructor
	{
		cout << "Copy constructor" << endl;
		this->ptr = new int;
	}
/*
The noexcept operator performs a compile-time check that returns true if an expression is declared to not throw any exceptions.

It can be used within a function template's noexcept specifier to declare that the function will throw exceptions for some types but not others.
*/


	A (A && a1) noexcept    // Move constructor //rvalue reference
	{
		cout << "Move constructor" << endl;
		this->ptr = a1.ptr;
		a1.ptr = nullptr;
	}
};


int main ()
{
	A a1;
	vector <A> v1;

	v1.push_back (A()); // push_back() makes a copy of the object that
			    // is being pushed back.
	v1.push_back (a1);  // This results in Copy constructor being called

	//v1.push_back (move (a1));
	
	//v1.push_back(A());  // This calls move constructor
	// move() is a function used to convert an lvalue reference into the rvalue reference.
	return 0;
}
