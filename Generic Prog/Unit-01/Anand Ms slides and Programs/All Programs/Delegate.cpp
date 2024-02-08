// Program to demonstrate constructor delegation in C++
#include <iostream>
using namespace std;
class A {
	int x, y, z;

public:
	A()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	// Constructor delegation
	A(int z) : A()
	{
		this->z = z; // Only update z
	}

	void show()
	{
		cout << x << '\n' << y << '\n' << z;
	}
};
int main()
{
	A obj(3);
	obj.show();
	return 0;
}
