#include <iostream>
using namespace std;

namespace ns 
{
    // Declaring a function.
    void func1();

    class Printer {
        public:
            // Declaring a method.
            void func2();
    };
}

// Defining func1().
void ns::func1() 
{
    cout << "func1() executed successfully" << endl;
}

// Defining func2().
void ns::Printer::func2() 
{
    cout << "func2() executed successfully" << endl;
}

// Driver code
int main() 
{
    // Creating an object to execute func2().
    ns::Printer obj;

    // Executing func1().
    ns::func1();

    // Executing func2().
    obj.func2();

    return 0;
}
