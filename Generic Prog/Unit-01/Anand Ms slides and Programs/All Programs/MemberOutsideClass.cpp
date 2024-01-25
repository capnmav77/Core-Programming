// C++ program to demonstrate function declaration outside class

#include <bits/stdc++.h>
using namespace std;
class Univs
{
	public:
	string univName;
	int id;
	
	// printname is not defined inside class definition
	void printname();
	
	// printid is defined inside class definition
	void printid()
	{
		cout <<"Univ id is: "<<id;
	}
};

// Definition of printname using scope resolution operator ::
void Univs::printname()
{
	cout <<"University name is: "<<univName;
}
int main() 
{
	
	Univs obj1;
	obj1.univName = "PES University";
	obj1.id=1;
	
	// call printname()
	obj1.printname();
	cout << endl;
	
	// call printid()
	obj1.printid();
	return 0;
}
