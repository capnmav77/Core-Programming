#include <iostream>

using namespace std;

// Creating a simple class in C++.
class FunctorCreation 
{
    public:
        // Overloading the function call operator ().
        void operator()() 
	{
            cout << "Operation Successful";
        }
};

int main(void) 
{
    // Creating the instance of the class.
    FunctorCreation functor;

    // Calling the created object like a normal function.
    functor();

    return 0;
}
