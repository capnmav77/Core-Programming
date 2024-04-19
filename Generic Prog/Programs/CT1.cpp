#include <iostream>
using namespace std;

template <typename T> 
class wrapper 
{ 
	// template definition 
}; 
void use_wrapper(wrapper<int>* ptr) 
{ 
	std::cout << ptr->get() << '\n'; 
} 

int main() 
{ 
	wrapper<int> a(42); // error, incomplete type 
	use_wrapper(&a);
}
