#include <iostream>
using namespace std;

class A {
	int i;
public:
	A(int );
	int getI() const { return i; }
};

A::A(int i):i(i) { } // Either Initializer list or this pointer must be used
/* The above constructor can also be written as
A::A(int i) {
	this->i = i;
}
*/

int main() {
	A a(10);
	cout<<a.getI();
	return 0;
}
/* OUTPUT:
	10
*/
