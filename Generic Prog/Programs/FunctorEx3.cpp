#include <iostream>

using namespace std;

// Creating a simple class in C++.
class HowFunctorsPreserveState {
    private:
        // Defining a num data variable of the above class.
        int num;

    public:
        // Constructor definition.
        HowFunctorsPreserveState(int x): num(x) {}

        // Overloading the function call operator () to return the sum 
        // of data members and the accepted argument.
        int operator()(int y) const {
            return num + y;
        }
};

int main(void) {
    // Creating the instance of the class.
    HowFunctorsPreserveState functor(10);

    // Calling the object like a normal function.
    // Here, we can see that we do not need to pass 10 again and again, 
    // demonstrating functors preserving the state.
    cout << functor(4) << endl; //output : 14
    cout << functor(7) << endl; //output : 17

    return 0;
}
