#include <iostream>
using namespace std;

// 1st part of the namespace
namespace ns 
{
    int
    var = 20;
}

// 2nd part of the namespace ns.
namespace ns 
{
    void func() 
    {
        cout << "The value of var is: " <<
            var << endl;
    }
}

int main() 
{
    // Running the function func().
    ns::func();

    return 0;
}
