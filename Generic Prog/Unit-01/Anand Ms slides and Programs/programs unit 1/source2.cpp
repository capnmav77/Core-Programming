// source2.cpp 
#include "wrapper.h" 
#include <iostream> 
void g() 
{ 
	wrapper<int> a{ 100 }; 
	std::cout << a.data << '\n'; 
}