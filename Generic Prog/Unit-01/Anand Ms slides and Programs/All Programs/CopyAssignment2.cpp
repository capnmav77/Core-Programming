// CPP Program to demonstrate the use of copy constructor and assignment operator
#include <iostream>
#include <stdio.h>
using namespace std;

class Test 
{
	public:
		Test() {}
		Test(const Test& t)
		{
			cout << "Copy constructor called " << endl;
		}

		Test& operator=(const Test& t)
		{
			cout << "Assignment operator called " << endl;
			return *this;
		}
};

// Driver code
int main()
{
	int i = 10;
	int j = i; // copy constructor is called which is a shallow copy
	Test t1, t2; // default constructor is called
	t2 = t1;	// assignment operator is called which is a shallow copy
	Test t3 = t1; // copy constructor is called which is a deep copy? No, it is a shallow copy why?
	cout << "value of j is: " << j << endl;
	getchar();
	return 0;
}
