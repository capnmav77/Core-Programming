// C++ program to demonstrate working of auto and type inference

#include <typeinfo>
#include <iostream>

using namespace std;

int main()
{
	// auto tmp;
	auto xint = 4;
	auto yfloat = 3.37;
	auto ptr = &xint;
	cout << typeid(xint).name() << endl
		<< typeid(yfloat).name() << endl
		<< typeid(ptr).name() << endl;
	return 0;
}
