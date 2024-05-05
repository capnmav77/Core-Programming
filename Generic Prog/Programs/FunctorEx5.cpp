#include <iostream>

using namespace std;

// Creating a simple class in C++.
class FunctorWithMemberVariables {
    private:
        // Declaring a member variable.
        int initialNum;

    public:
        // Definition of parameterized Constructor.
        FunctorWithMemberVariables(int num) {
            initialNum = num;
        }

    // Overloading the function call operator to return the division of two numbers.
    double operator()(int num2) {
        return (initialNum / (double) num2);
    }
};

int main(void) {
    // Creating an instance of the class.
    FunctorWithMemberVariables functor(100);

    // Calling the created object as a normal function.
    double returnedSum = functor(12); // 100 / 12 = 8.33333

    // Printing the value.
    cout << "The returned value is : " << returnedSum << endl;

    return 0;
}
