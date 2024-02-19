// main.cpp 
#include "wrapper.h" 
extern void f(void);
extern void g();

int main() 
{ 
	wrapper<int> a{ 0 }; 
	f();
	g();
} 
