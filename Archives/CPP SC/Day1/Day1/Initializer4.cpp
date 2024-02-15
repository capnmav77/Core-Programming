#include <iostream>
using namespace std;

class A {
	int i;
public:
	A(int );
};

A::A(int arg) {
	i = arg;
	cout << "A's Constructor called: Value of i: " << i << endl;
}

// Class B contains object of A
class B {
	A a;
public:
	B(int );
};

B::B(int x):a(x) { //Initializer list must be used
	cout << "B's Constructor called";
}

int main() {
	B obj(10);
	return 0;
}
/* OUTPUT:
	A's Constructor called: Value of i: 10
	B's Constructor called
*/
