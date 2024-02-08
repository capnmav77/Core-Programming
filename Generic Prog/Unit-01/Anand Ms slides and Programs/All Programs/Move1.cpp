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
	A (A && a1)       // Move constructor
	{
		cout << "Move constructor" << endl;
		this->ptr = a1.ptr;
		a1.ptr = nullptr;
	}
};

int main ()
{
	//A a2;
	vector <A> v1;
	//v1.push_back (a2);
	v1.push_back (A()); // push_back makes a copy of the object that is being pushed back
	return 0;
}
