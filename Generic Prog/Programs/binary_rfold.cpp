#include <iostream> 

template<typename... Args> 
int sum(Args&&... args) 
{ 
	return (args + ...); // Performs a binary right fold with addition 
} 
int main() 
{ 
	int result = sum(1, 2, 3, 4); 
	std::cout << "Result: " << result << std::endl; 
	return 0; 
}