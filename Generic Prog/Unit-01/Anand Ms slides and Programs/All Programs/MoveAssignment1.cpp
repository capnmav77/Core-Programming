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
		// cout << "Destructor" << endl;
		delete ptr;
	}
	A (const A &a1)   // Copy constructor
	{
		cout << "Copy constructor" << endl;
		this->ptr = new int;
	}
	A (A && a1)  noexcept    // Move constructor
	{
		cout << "Move constructor" << endl;
		this->ptr = a1.ptr;
		a1.ptr = nullptr;
	}
/*
	A &operator=(A &&obj)   // Move assignment operator
	{
		cout << "Move assignment called" << endl;
		return *this;
	}
*/

};

int main ()
{
	A a1;
	vector <A> v1;
	v1.push_back (A());
	v1.push_back (a1);  // This results in Copy constructor being called

	// std::move() is a function used to convert an lvalue reference 
	// into the rvalue reference. 
 	v1.push_back (move (a1));  // This calls move constructor
	return 0;
}
