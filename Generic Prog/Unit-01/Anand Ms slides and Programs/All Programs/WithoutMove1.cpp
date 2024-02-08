// C++ program to implement the above approach

#include <string>

#include <iostream>

// for EXIT_SUCCESS macro
#include <cstdlib>

#include <vector>

// for std::move()
#include <utility>

// Declaration
std::vector<std::string> createAndInsert();

// Driver code
int main()
{
	// Constructing an empty vector of strings
	std::vector<std::string> vecString;

	// calling createAndInsert() and initializing the local vecString object
	vecString = createAndInsert();

	// Printing content of the vector
	for (const auto& s : vecString) {
		std::cout << s << '\n';
	}

	return EXIT_SUCCESS;
}

// Definition
std::vector<std::string> createAndInsert()
{
	// constructing a vector of strings with an size of 3 elements
	std::vector<std::string> vec;
	vec.reserve(3); // reserve vector capacity be at least enough to contain 3 elements

	// constructing & initializing a string with "Hello"
	std::string str("Hello");

	// Inserting a copy of string object
	vec.push_back(str);

	// Inserting a copy of a temporary string object
	vec.push_back(str + str);

	// Again inserting a copy of string object
	vec.push_back(std::move(str));

	// Finally, returning the local vector
	return vec;
}
