// C++ Program to implement use of template
#include <iostream>
using namespace std;

template <class T, class U = char> class A {
public:
	T x;
	U y;
	A() { cout << "Constructor Called" << endl; }
};

int main()
{
	// This will call A<char, char>
	A<char> a;

	return 0;
}
