/*
an example to access the static member function using the object and class in the C++ programming language.
*/

#include <iostream>  
using namespace std;  
class Member  
{  
  
private:  
	// declaration of the static data members  
	static int A;  
	static int B;  
	static int C;  
  
	// declare public access specifier  
public:  
	// define the static member function  
	static void disp ()  
	{  
		cout << " The value of the A is: " << A << endl;  
		cout << " The value of the B is: " << B << endl;  
		cout << " The value of the C is: " << C << endl;  
	}  
};  
// initialization of the static data members  
int Member :: A = 20;  
int Member :: B = 30;  
int Member :: C = 40;  
  
int main ()  
{  
	// create object of the class Member  
	Member mb;  
	// access the static member function using the class object name  
	cout << " Print the static member through object name: " << endl;  
	mb. disp();  
	// access the static member function using the class name  
	cout << " Print the static member through the class name: " << endl;  
	Member::disp();  
	return 0;  
}  