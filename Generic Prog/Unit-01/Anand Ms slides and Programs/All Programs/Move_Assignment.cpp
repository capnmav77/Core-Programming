#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test
{
	private:
	static const int SIZE = 100;
	int *_pBuffer {nullptr};

	public:
	Test ()
	{
		_pBuffer = new int [SIZE] {};
	}
	Test (int)
	{
		_pBuffer = new int [SIZE] {};
		for (int i = 0; i < SIZE; i ++)
			_pBuffer [i] = 7;
	}
	Test (const Test &other)   // copy constructor
	{
		cout << "Copy constructor being called" << endl;
		_pBuffer = new int [SIZE] {};
		memcpy (_pBuffer, other._pBuffer, SIZE * sizeof (int));
	}
	Test (Test &&other)        // move constructor
	{
		cout << "Move constructor" << endl;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
	}
	Test &operator=(const Test &other)  // copy assignment operator
	{
		cout << "Copy assignment operator being called" << endl;
		_pBuffer = new int [SIZE]{};
		memcpy (_pBuffer, other._pBuffer, SIZE * sizeof (int));
		return *this;
	}

	Test &operator=(Test &&other)     // move assignment operator
	{
		cout << "Move assignment operator being called" << endl;
		delete [] _pBuffer;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;
		return *this;
	}

	~Test ()
	{
		delete [] _pBuffer;
	}

};

Test getTest()
{
	return Test ();
}

int main ()
{
	vector <Test> vec;
  	cout << "Before push_back" << endl;
	vec.push_back (Test ());
        cout << "After push_back" << endl;
	Test test = getTest ();
	Test test1;
        cout << "Before test1 is assigned the return value" << endl;
	test1 = getTest ();    // results in move assignment being called
	return 0;
}		 
	