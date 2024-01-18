#include <iostream>

using namespace std;

int main ()
{
	int in1, in2;
	string str1;
	char buf [40];
	
	cout << "Sample program to show IO operations\n";

	cout << "Key in two numbers and a string: ";
	cin >> in1 >> in2 >> str1;
	cout << "The keyed in values are: " << "Int1 is "<< in1 <<endl << "Int2 is "<< in2 << endl << "String is " << str1 << endl;
	cin.ignore(1000, '\n');    // How does this call help?
	cout << "Waiting for a number to be keyed in: ";
	if (cin >> in2)    // Successful input operation
	{
		cout << "The remaining data is " << in2 << endl;
		cout << "Key in a sentence with multiple words:";
		cin.ignore(1000, '\n');
		cin.getline (buf, 30);
		cout << "The sentence is: " << buf;
	}
	
	else
		cout << "Wrong type of input entered" << endl;
	return 0;
}
