#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T> class A{};
template<int i> class B{};

class C{
    public:
    int x;
};

class D
{
    public:
    C y;
    int z; 
};

template<class T> void f(T){
    cout<<"T"<<endl;
}

template<class T> void f1(const T)    
{ 
	cout << "const T" << endl; 
};

template<class T> void f2(volatile T) 
{ 
	cout << "volatile T" << endl;  
};

//overload the reference 
template<class T> void g(T*){
    cout<<"T*"<<endl;
}

//overload pointer 
template<class T> void g(T&){
    cout<<"T&"<<endl;
}

// g1 demonstrates the use of arrays as template parameters overloading
template<class T> void g1(T[10])      
{ 
	cout << "T[10]" << endl;
};

template<class T> void h1(A<T>)       
{ 
	cout << "A<T>" << endl; 
};


void test_1(){
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
template<class T>          
void j(C(*)(T)) 
{ 
	cout << "C(*) (T)" << endl; 
};

template<class T>          
void j(T(*)())  
{ 
	cout << "T(*) ()" << endl; 
}

template<class T, class U>
void j(T(*)(U)) 
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


int main()
{
    //test_1();
    test_2();
    return 0;
}