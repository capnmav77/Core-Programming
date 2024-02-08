#include <algorithm> 
#include <iostream> 
using namespace std;

int main() 
{ 
	int arr[] = {3, 5, 1, 2, 4}; 
	float fl[] = {2.2, 3.3, 1.1, 5.5, 4.4};

	// Sort the array in ascending order 
	sort(begin(arr), end(arr)); 

	// Print the sorted array 
	for (int i : arr) 
	{ 
		cout << i << "  "; 
	} 

	cout << endl;

	// Sort the array in ascending order 
	sort(begin(fl), end(fl)); 

	// Print the sorted array 
	for (float f : fl) 
	{ 
		cout << f << "  "; 
	} 

	return 0; 
} 
