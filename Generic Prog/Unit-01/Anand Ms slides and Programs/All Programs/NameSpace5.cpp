#include <iostream>
using namespace std;

namespace outer_ns 
{
    void func1() {
        cout << "This function is inside the outer namespace." << endl;
    }

    namespace inner_ns 
    {
        void func2() {
            cout << "This function is inside the inner namespace." << endl;
        }
    }
}

// Creating an alias for an outer namespace.
namespace o_ns = outer_ns;

// Creating an alias for an inner namespace.
namespace i_ns = outer_ns::inner_ns;

int main() 
{
    // Calling func1() from outer namespace.
    o_ns::func1();
    
    // Calling func2() from inner namespace.
    // no need to write o_ns::i_ns::func2().
    i_ns::func2();  
    // This is equivalent to outer_ns::inner_ns::func2();

    return 0;
}
