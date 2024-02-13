#include <iostream>
// #include <algorithm>
using namespace std;

template <typename Input, typename Predicate> 
int count_if(Input start, Input end, Predicate p) 
{ 
	int total = 0; 
	for (Input i = start; i != end; i++) 
	{ 
		cout << p(*i) << " ";
		if (p(*i)) 
			total++; 
	} 
	return total; 
} 


int main() 
{ 
	int arr[]{ 1,1,2,3,5,8,11 }; 
	// short s_arr[]{ 1,1,2,3,5,8,11 };
	int odds = count_if(begin(arr), end(arr), 
			[](int const n) { return n % 2 == 1; }); 
	cout << odds << '\n'; 
} 
