// C++ Program to Implement Member functions inside structure

#include <iostream>
using namespace std;

struct eStruct
{
    // Empty structure
};
struct marks
{
    static int sInt;   // Just to show that static members can be inside a struct
	int num;
	short s1 = 100; // Direct initialization

	// Member function inside Structure to take input and store it in "num"
	void Set(int temp) { num = temp; }

	// function used to display the values
	void display() { cout << "num=" << num << endl; }
};


int main()
{
	marks m1;

	// calling function inside Struct to initialize value to num
	m1.Set(9);

	// calling function inside struct to display value of Num
	m1.display();

	cout << "Size of an empty struture is: " << sizeof (struct eStruct) << endl;
	cout << "Size of an struture marks1 is: " << sizeof (struct marks1);
}
