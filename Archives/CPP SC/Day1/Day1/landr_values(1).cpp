// Sample Program demonstrating the use of real() and imag() function
#include <iostream>

using namespace std;

int setValue()
{
	return 6;
}

int global = 100;

int& setGlobal()
{
    return global;
}

// Main function for the program
int main()
{
    int x = 10;

    int *y = &x;  // (&x is an rvalue)

	// setValue() = 3; // error!

	setGlobal() = 400; // OK

    return 0;
}
