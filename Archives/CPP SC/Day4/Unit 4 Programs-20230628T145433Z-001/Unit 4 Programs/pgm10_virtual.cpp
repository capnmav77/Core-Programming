//virtual.cpp

#include <iostream>
using namespace std;

class Base {
 public:
	virtual void f() { cout << "Base::f()\n"; }
	void g() { cout << "Base::g()\n"; }
};

class Derived : public Base {
 public:
	void f() { cout << "Derived::f()\n"; }
	virtual void g() { cout << "Derived::g()\n"; }
};

int main() {
	Base b;
	Derived d;

	b = d;
	b.f();
	b.g(); 

	Base* pB =&d;
	pB->f();
	pB->g(); 
	return 0;
}

/*The calls b.f() and b.g() are directly by the object. Hence, they are statically bound and will call respective base class functions.

pB is defined as a pointer to d (Base* pB =&d). The function invocations after this definition, namely pB->f() and pB->g(), are by pointer to the object. Hence, they are dynamically bound and will dispatch the calls depending on whether the member function is virtual or not. As f() is virtual in base, it is dispatched to the actual object d and derived::f() is called for the call pB->f(). However, base::g() is called on the call pB->g() as g() is non-virtual in base. If g() was virtual in base, then pB->g() would have called derived::g().
*/
/*
Output:
Base::f()
Base::g()
Derived::f()
Base::g()
*/
