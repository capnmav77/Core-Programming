#include <iostream> 
using namespace std; 

template <typename... Args> bool all(Args... args) 
{ 
	return (... && args); 
} 

int main() 
{ 
	bool b = all(true, true, true, false); 
	cout << "Result: " << boolalpha << b << endl; 
	return 0; 
}