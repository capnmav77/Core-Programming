#include <iostream>
using namespace std;

// define a namespace called foo
namespace foo {
    // define a function called print
    void print() {
        cout << "This is foo::print" << endl;
    }
}

// define another namespace called bar
namespace bar {
    // define a function with the same name as foo::print
    void print() {
        cout << "This is bar::print" << endl;
    }
}

int main()
{
    // call the print function from foo namespace
    foo::print();

    // call the print function from bar namespace
    bar::print();

    return 0;
}
