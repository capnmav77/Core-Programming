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
	int j = i;
	Test t1, t2;
	t2 = t1;
	Test t3 = t1;
	cout << "value of j is: " << j << endl;
	getchar();
	return 0;
}
