// Friend functions can access both private and public members of a class
#include <iostream>

class MyClass {
private:
    int privateMember;

protected:
    int protectedMember;

public:
    MyClass(int privateVal, int protectedVal) : privateMember(privateVal), protectedMember(protectedVal) {}

    friend void friendFunction(MyClass obj);
};

void friendFunction(MyClass obj) {
    // Accessing private and protected members of MyClass
    int a = obj.privateMember;     // Accessing private member
    int b = obj.protectedMember;   // Accessing protected member

    // Perform some operations using the private and protected members
    std::cout << "Private member: " << a << std::endl;
    std::cout << "Protected member: " << b << std::endl;
}

int main() {
    MyClass obj(10, 20);

    // Calling the friend function
    friendFunction(obj);

    return 0;
}
