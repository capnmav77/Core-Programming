#include <iostream>
using namespace std;

template <typename T> 
struct foo 
{ 
	static T data;
}; 

template <typename T> T foo<T>::data = 0; 
int main() 
{ 
	foo<int> a; 
	foo<double> b; 
	foo<double> c; 
	std::cout << a.data << '\n'; // 0 
	std::cout << b.data << '\n'; // 0 
	std::cout << c.data << '\n'; // 0 

	b.data = 42; 
	std::cout << a.data << '\n'; // 0 
	std::cout << b.data << '\n'; // 42 
	std::cout << c.data << '\n'; // 42 
} 
