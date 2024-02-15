// source1.cpp 
#include "wrapper.h" 
#include <iostream> 
template struct wrapper<int>; // [2]
void f() 
{ 
	struct wrapper<int> a{ 42 }; 
	std::cout << a.data << '\n'; 
}
