#include <iostream>

template <typename T> 
T min(T a, T b) 
{ 
	return a < b ? a : b; 
}
template <typename T, typename... Args> 
T min(T a, Args... args) 
{ 
	return min(a, min(args...)); 
}
int main() 
{ 
	std::cout << "min(42.0, 7.5)=" << min(42.0, 7.5) 
		<< '\n'; 
	std::cout << "min(1,5,3,-4,9)=" << min(1, 5, 3, -4, 9) 
		<< '\n'; 
} 
