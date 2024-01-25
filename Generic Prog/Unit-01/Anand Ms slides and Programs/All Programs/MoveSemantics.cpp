// C++ program using the move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declare the raw pointer as the data member of class
	int* data;

public:

	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
		*data = d;
		//cout << "Constructor is called for " << d << endl;
	};

	// Copy Constructor
	Move(const Move& source) : Move{ *source.data }
	{
		// Copying the data by making deep copy
		cout << "Copy Constructor is called -"
			<< "Deep copy for " << *source.data << endl;
	}

	// Move Constructor
	Move(Move&& source) : data{ source.data }
	{
		cout << "Move Constructor for " << *source.data << endl;
		source.data = nullptr;
	}

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If pointer is not pointing to nullptr
			cout << "Destructor is called for " << *data << endl;
		else

			// If pointer is pointing to nullptr
			cout << "Destructor is called" << " for nullptr " << endl;

		// Free up the memory assigned to the data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Vector of Move Class
	vector<Move> vec;

	// Inserting Object of Move Class
	vec.push_back(Move{ 10 });
	vec.push_back(Move{ 20 });
	return 0;
}
