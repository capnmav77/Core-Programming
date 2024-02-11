#include <iostream>

using namespace std;

void fn (int &ref)
{
	cout << "Normal call" << endl;
}

void fn (int &&ref)
{
	cout << "rval ref" << endl;
}

int main()
{
	int i = 10;
	fn (i);
	fn (10);
	return 0;
}
