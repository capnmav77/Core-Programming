// C++ program to demonstrate the use of rand() to get value in a range of lb to ub
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int lb = 20, ub = 100;
	// This program will create some sequence of random
	// numbers on every program run within range lb to ub
	for (int i = 0; i < 5; i++)
		cout << (rand() % (ub - lb + 1)) + lb << " ";

	return 0;
}

// This code is contributed by Susobhan Akhuli
