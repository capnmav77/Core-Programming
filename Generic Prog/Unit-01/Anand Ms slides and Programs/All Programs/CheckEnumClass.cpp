// Program to demonstrate working of Enum Classes

#include <iostream>
using namespace std;

int main()
{

	enum class Color { Red, Green, Blue };
	enum class Color2 { Red, Black, White };
	enum class People { Good, Bad };

	// An enum value can now be used to create variables
	int Green = 10;

	// Instantiating the Enum Class
	Color x = Color::Green;

	// Comparison now is completely type-safe
	if (x == Color::Red)
		cout << "It's Red\n";
	else
		cout << "It's not Red\n";

	People p = People::Good;

	if (p == People::Bad)
		cout << "Bad people\n";
	else
		cout << "Good people\n";

	// gives an error
	// if(x == p)
	// cout<<"red is equal to good";

	// won't work as there is no
	// implicit conversion to int
	// cout<< x;

	cout << int(x);

	return 0;
}
