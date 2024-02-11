// In C++ We can Initialize the Variables with Declaration in Structure.
// Program taken from geeksforgeeks.com

#include <iostream>
using namespace std;

struct Point 
{
	int x = 0; // It is Considered as Default Argument and no Error is Raised
	int y = 1;
};  // We cannot initialize structure members in C

int main()
{
	// struct Point p1;  // The use of the word struct is optional in C++
	// Point p1;
	/* We can initialize structure members using curly braces */
	Point p1 = {10, 20};

	// Accessing members of point p1
	// If no value is Initialized, then the default value is considered. ie x=0 and y=1;
	cout << "x = " << p1.x << ", y = " << p1.y<<endl;

	p1.y = 40;
	cout << "x = " << p1.x << ", y = " << p1.y;
	return 0;
}
