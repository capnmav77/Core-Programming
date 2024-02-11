#include <iostream>
using namespace std;

// first name space
namespace my_first_space
{
    int m_first = 100;
    void my_func()
    {
        cout << "Inside my_first_space" << endl;
    }
}

// second name space
namespace my_second_space
{
	void my_func()
	{
		cout << "Inside my_second_space" << endl;
	}
}

int main ()
{
    int m_first = 200;
    // This calls function from second name space.
    my_second_space::my_func();
    cout << "The value of m_first from the namespace is: " << my_first_space::m_first << endl;
    cout << "The value of m_first from main is: " << m_first << endl;
    return 0;
}
