#include <iostream> 
using namespace std; 

template <typename... Args> 
int multiply_and_add(Args... args) 
{ 
	return (1 * ... * args); // Error: operator with 
							// precedence below cast 
} 

int main() 
{ 
	int result = multiply_and_add(1, 2, 3, 4); 
	cout << "Result: " << result; 
	return 0; 
}

