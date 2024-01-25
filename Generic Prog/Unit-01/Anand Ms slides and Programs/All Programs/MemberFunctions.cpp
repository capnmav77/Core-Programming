// C++ program to demonstrate function declaration outside class

#include <iostream>
#include <string>

using namespace std;
class PES_Univ
{
	public:
	string univ_name;
	int id;

	// printname is not defined inside class definition
	void printname();

	// printid is defined inside class definition
	void printid()
	{
		cout << "University id is: " << id;
	}
};

// Definition of printname using scope resolution operator ::
void PES_Univ::printname()
{
	cout << "University name is: " << univ_name;
}
int main()
{

	PES_Univ obj1;
	obj1.univ_name = "PESU";
	obj1.id=15;

	// call printname()
	obj1.printname();
	cout << endl;

	// call printid()
	obj1.printid();
	return 0;
}
