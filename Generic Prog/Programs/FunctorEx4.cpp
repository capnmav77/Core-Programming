#include <iostream>

using namespace std;

// Creating a simple class in C++.
class FunctorWithReturnType {
    public:
        // Overloading the function call operator () to compute the product of two numbers.
        int operator()(int num1, int num2) {
            return num1 * num2;
        }
};

int main(void) {
    // Creating an instance of the class.
    FunctorWithReturnType functor;

    // Calling the function object with 10 and 20 AS parameters to compute the product.
    int product = functor(10, 20);

    // Printing the value.
    cout << "The value of the product is : " << product << endl;

    return 0;
}
