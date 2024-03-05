#include <iostream>
using namespace std;

//take in single template parameter and print the type of the parameter
template<class T> class A { }; // A is a class and it takes  generic class as input with T as class
template<int i> class B { }; // B is a generic class that takes an integer as a template parameter

// C & D are simple classes that a\have public member variables 
class C 
{
   public:
      int x;
};

class D 
{
   public:
      C y;
      int z;
};

// f1,f2,f3 are function templates that take in a single parameter and print the type of the parameter
// demonstrate the use of const and volatile qualifiers with template parameters
template<class T> void f (T)          
{ 
	cout << "T" << endl; 
};

template<class T> void f1(const T)    
{ 
	cout << "const T" << endl; 
};

template<class T> void f2(volatile T) 
{ 
	cout << "volatile T" << endl;  
};


// g demonstrates the use of pointers and references as template parameters overloadings
template<class T> void g (T*)         
{ 
	cout << "T*" << endl; 
};

template<class T> void g (T&)         
{ 
	cout << "T&" << endl; 
};

// g1 demonstrates the use of arrays as template parameters overloading
template<class T> void g1(T[10])      
{ 
	cout << "T[10]" << endl;
};

// h1 function is a template function that takes in a single parameter of type A<T> and prints the type of the parameter
// A<T> is a class identifier and it's a generic class , and T is the template parameter
// A<T> represents A of type T -> A[T]
template<class T> void h1(A<T>)       
{ 
	cout << "A<T>" << endl; 
};


void test_1() 
{
   A<char> a;
   C c;

   f(c);   f1(c);   f2(c);
   g(c);   g(&c);   g1(&c);
   h1(a);
}

//j demonstrates the use of function pointers as template parameters overloading 
// how do we know it's a function pointer ? 
// ans: we know it's a function pointer because of the syntax used in the function signature i.e the * symbol is used to denote a function pointer
// breakdown the syntax of the function signature = template<class T> void j(T(*)(U)) where T is the return type of the function pointer and U is the parameter type of the function pointer
template<class T>          void j(C(*)(T)) 
{ 
	cout << "C(*) (T)" << endl; 
};

template<class T>          void j(T(*)())  
{ 
	cout << "T(*) ()" << endl; 
}

template<class T, class U> void j(T(*)(U)) 
{ 
	cout << "T(*) (U)" << endl; 
};


void test_2() 
{
   C (*c_pfunct1)(int);
   C (*c_pfunct2)(void);
   int (*c_pfunct3)(int);
   j(c_pfunct1);
   j(c_pfunct2);
   j(c_pfunct3);
}

// k demonstrates the use of member pointers as template parameters overloading 
// how do we know it's a member pointer ?
// ans: we know it's a member pointer because of the syntax used in the function signature i.e the * symbol is used to denote a member pointer
// breakdown the syntax of the function signature = template<class T> void k(T C::*) -> where T is the type of the member pointer and C is the class that the member pointer is pointing to
template<class T>          void k(T C::*) 
{ 
	cout << "T C::*" << endl; 
};

template<class T>          void k(C T::*) 
{ 
	cout << "C T::*" << endl; 
};

template<class T, class U> void k(T U::*) 
{ 
	cout << "T U::*" << endl; 
};

void test_3() 
{
   k(&C::x);
   k(&D::y);
   k(&D::z);
} 

// m demonstrates the use of member function pointers as template parameters overloading
// breakdown of syntax m(C (T::*)(U)) -> where C is the return type of the member function pointer, T is the class that the member function pointer is pointing to and U is the parameter type of the member function pointer
template<class T>     void m(T (C::*)() )
{ 
	cout << "T (C::*)()" << endl; 
};

template<class T>     void m(C (T::*)() )
{ 
	cout << "C (T::*)()" << endl; 
};

template<class T>     void m(D (C::*)(T))
{ 
	cout << "D (C::*)(T)" << endl; 
};

template<class T, class U>  void m(C (T::*)(U))
{ 
	cout << "C (T::*)(U)" << endl; 
};

template<class T, class U>  void m(T (C::*)(U))
{ 
	cout << "T (C::*)(U)" << endl; 
};

template<class T, class U>  void m(T (U::*)() )
{ 
	cout << "T (U::*)()" << endl; 
};

template<class T, class U, class V> void m(T (U::*)(V))
{ 
	cout << "T (U::*)(V)" << endl; 
};

void test_4() 
{
   int (C::*f_membp1)(void);
   C (D::*f_membp2)(void);
   D (C::*f_membp3)(int);
   m(f_membp1);
   m(f_membp2);
   m(f_membp3);

   C (D::*f_membp4)(int);
   int (C::*f_membp5)(int);
   int (D::*f_membp6)(void);
   m(f_membp4);
   m(f_membp5);
   m(f_membp6);

   int (D::*f_membp7)(int);
   m(f_membp7);
}

// n demonstrates the use of arrays as template parameters overloading
// breakdown of syntax n(C[10][i]) -> where C is the type of the array, 10 is the size of the first dimension of the array and i is the size of the second dimension of the array
template<int i> void n(C[10][i]) 
{ 
	cout << "E[10][i]" << endl; 
};

// breakdown of syntax n(B<i>) -> where B is the type of the array and i is the size of the array
// B<20> is the same as B[20] and B<0> is the same as B[0]
template<int i> void n(B<i>)     
{ 
	cout << "B<i>" << endl; 
};


void test_5() 
{
   C array[10][20];
   n(array);
   B<20> b;
   n(b);
}
// p1 demonstrates the use of template template parameters overloading
// breakdown of syntax p1(TT<T>) -> where TT is the template template parameter and T is the template parameter
// a template template parameter is a template parameter that takes a template as an argument
template<template<class> class TT, class T> void p1(TT<T>)
{ 
	cout << "TT<T>" << endl; 
};

template<template<int> class TT, int i>     void p2(TT<i>)
{ 
	cout << "TT<i>" << endl; 
};

template<template<class> class TT>          void p3(TT<C>)
{ 
	cout << "TT<C>" << endl; 
};


void test_6() 
{
   A<char> a;
   B<20> b;
   A<C> c;
   p1(a);
   p2(b);
   p3(c);
}

int main(void) 
{ 
	test_1(); test_2(); test_3(); test_4(); test_5(); test_6(); 
	return 0;
}