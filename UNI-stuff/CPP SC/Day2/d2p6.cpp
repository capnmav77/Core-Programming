#include <iostream> // For cout
#include <cstdlib> // For malloc and free
using namespace std;

// Define the class Foo
class Foo {
private:
    int x;
public:
    // Constructor
    Foo(int x) {
        this->x = x;
        cout << "Foo created with x = " << x << endl;
    }

    // Destructor
    ~Foo() {
        cout << "Foo destroyed with x = " << x << endl;
    }
};

// Driver code
int main() {
    // Allocate memory using malloc
    Foo* p = (Foo*)malloc(sizeof(Foo));

    // Call constructor using placement new
    new (p) Foo(10);

    // Do something with p
    cout << "p points to " << p << endl;

    // Call destructor explicitly
    p->~Foo();

    // Deallocate memory using free
    free(p);

    return 0;
}
