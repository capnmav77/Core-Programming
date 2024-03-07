#include <iostream> 

template<typename... Args> 
bool any(Args... args) { 
	return (... || args); 
} 

int main(void) 
{ 
	bool b = any(false, false, false); 
	std::cout << "Result: " << std::boolalpha << b << std::endl; 
	return 0; 
}
