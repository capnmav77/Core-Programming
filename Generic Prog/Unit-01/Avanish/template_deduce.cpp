#include <iostream>
using namespace std;

template<class T> class A { };
template<int i> class B { };

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

template<class T> void g (T*)         
{ 
	cout << "T*" << endl; 
};

template<class T> void g (T&)         
{ 
	cout << "T&" << endl; 
};

template<class T> void g1(T[10])      
{ 
	cout << "T[10]" << endl;
};

template<class T> void h1(A<T>)       
{ 
	cout << "A<T>" << endl; 
};

//done
void test_1() 
{
   A<char> a;
   C c;

   f(c);   f1(c);   f2(c);
   g(c);   g(&c);   g1(&c);
   h1(a);
}

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

//done
void test_2() 
{
   //function pointer
   C (*c_pfunct1)(int);
   C (*c_pfunct2)(void);
   int (*c_pfunct3)(int);
   j(c_pfunct1);
   j(c_pfunct2);
   j(c_pfunct3);
}

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

//ok ig
void test_3() 
{
   k(&C::x);
   k(&D::y);
   k(&D::z);
}

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

//done
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

template<int i> void n(C[10][i]) 
{ 
	cout << "E[10][i]" << endl; 
};

template<int i> void n(B<i>)     
{ 
	cout << "B<i>" << endl; 
};

//Done
void test_5() 
{
   C array[10][20];
   n(array);
   B<20> b;
   n(b);
}

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