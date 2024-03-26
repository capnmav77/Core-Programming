// #include<bits/stdc++.h>

// using namespace std;


// class SmartPointer
// {
//     int *ptr; //actual pointer

// public:
//     //constructor
//     explicit SmartPointer(int *p = NULL) { cout<<"init the pointer"; ptr = p; }

//     //destructor
//     ~SmartPointer() { cout<<"deleting the pointer"; delete (ptr); }

//     //overloading dereferencing operator
//     int &operator*() { return *ptr; }
// };

// int main()
// {
//     SmartPointer ptr(new int());
//     *ptr = 20;
//     cout << *ptr;
//     return 0;
// }


#include <iostream>

class MyClass {
public:
    // Parameterized constructor with explicit
    explicit MyClass(int value1, int value2) {
        std::cout << "Constructor called with values: " << value1 << ", " << value2 << std::endl;
    }
};

int main() {
    // Uncommenting the line below would result in a compilation error
    // MyClass obj1 = {10, 20}; // Error: Cannot convert from initializer list to MyClass implicitly

    MyClass obj2{10, 20};  // Explicit constructor call with initializer list

    return 0;
}
