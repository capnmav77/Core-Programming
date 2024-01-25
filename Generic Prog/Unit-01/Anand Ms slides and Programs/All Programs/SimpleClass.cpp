// C++ program to demonstrate accessing of data members
#include <bits/stdc++.h>
using namespace std;
class Pesu
{
	// Access specifier
	public:
		// Data Members
		string univName;
		// Member Functions()
		void printname() 
		{ 
			cout << "Name of the university is:" << univName; 
		}
};

int main()
{
	// Declare an object of class Pesu
	Pesu obj1;
	// accessing data member
	obj1.univName = "PES University";
	// accessing member function
	obj1.printname();
	return 0;
}
