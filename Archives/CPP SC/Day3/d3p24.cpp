#include <iostream>

class MyClass {
public:
    static int staticVar;

    static void staticFunction() {
        std::cout << "Static Variable: " << staticVar << std::endl;
    }
};

// Initialize static member
int MyClass::staticVar = 10;

int main() {
    // Call static function
    MyClass::staticFunction(); // Output: "Static Variable: 10"

    // Access static member directly
    MyClass::staticVar = 20;

    MyClass::staticFunction(); // Output: "Static Variable: 20"

    return 0;
}
