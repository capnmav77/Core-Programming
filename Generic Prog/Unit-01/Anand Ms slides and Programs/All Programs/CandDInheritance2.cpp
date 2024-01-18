#include <iostream>
using namespace std;

class parent
{

    int x;
    public:

    // parameterized constructor
    parent(int i)
    {
        x = i;
	cout << "x is " << x << endl;
        cout << "Parent class Parameterized Constructor\n";
    }
    ~parent ()
    {
        cout << "Parent class destructor called\n";
    }
};

class child: public parent
{

    int y;
    public:

    // parameterized constructor
    child(int j) : parent(j)  //Explicitly calling
    {
        y = j;
        cout << "Child class Parameterized Constructor\n";
	cout << "y is " << y << endl;
    }
    ~child ()
    {
	cout << "Child destructor called\n";
    }
};

int main()
{
    child c(10);

    return 0;
}
