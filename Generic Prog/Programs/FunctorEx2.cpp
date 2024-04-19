#include <iostream>

using namespace std;

// Creating a simple class in C++.
class SquareUsingFunctors {
    public:
        // Overloading the function call operator () to compute the square of a number.
        int operator()(int num) {
            return (num * num);
        }
};

int main(void) {
    // Creating the instance of the class.
    SquareUsingFunctors functor;

    // Calling the object like a normal function.
    cout << functor(4);

    return 0;
}
