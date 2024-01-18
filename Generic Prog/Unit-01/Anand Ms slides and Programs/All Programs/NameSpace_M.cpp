#include <iostream>
using namespace std;

/* var is defined in the global namespace, i.e., 
   this variable exists everywhere in the program */
int var = 10;  

namespace ns 
{
    // This var is defined in a non-global namespace ns, i.e., it does not exist 
    // outside this namespace.
    int var = 100;     

    void print_numbers() {
        // This var is defined inside a function, i.e., it does not exist outside it.
        int var = 1000; 

        // Calling var present in the global namespace.
        cout << "The value of ::var is --> " << :: var << endl;

        // Calling var present in the namespace ns.
        cout << "The value of ns::var is --> " << ns::var << endl;

        // Calling var present inside this function.
        cout << "The value of var is --> " <<
            var << endl;
    }
}

int main() 
{
    // Running the function print_numbers.
    ns::print_numbers();

    return 0;
}
