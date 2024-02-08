#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
	int i;
	short j;
	long l;
	float f;
	char c, *d;
	double e;
	int *ip;
	
	// Printing the types of the variables of different data type on the console
	cout << typeid(i).name() << endl;
	cout << typeid(j).name() << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
	cout << typeid(*d).name() << endl;
	cout << typeid(ip).name() << endl;
	cout << typeid(l).name() << endl;
	
	return 0;
}
