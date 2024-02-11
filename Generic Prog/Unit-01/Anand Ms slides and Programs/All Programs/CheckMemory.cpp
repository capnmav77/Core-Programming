// Program to demonstrate constructor delegation in C++
#include <iostream>
using namespace std;
class A {
	int *x;

public:
	A()
	{
		x = new (int);
		cout << "Inside constructor";
	}

	// Destructor
	~A()
	{
		cout << "Inside destructor";
		delete (this->x);
	}

	
};

int main()
{
	A obj;
	// obj.show();
	return 0;
}
