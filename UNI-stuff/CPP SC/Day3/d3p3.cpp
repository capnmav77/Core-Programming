#include <iostream>

class MyClass {
private:
    int privateMember;

public:
    MyClass(int privateVal) : privateMember(privateVal) {}
    // Friend Class

    friend class FriendClass;
};

class FriendClass {
public:
    void friendFunction(MyClass obj) {
        std::cout << "Accessing private member through member friend function: " << obj.privateMember << std::endl;
    }
};

int main() {
    MyClass obj(10);
    FriendClass friendObj;

    friendObj.friendFunction(obj);

    return 0;
}
