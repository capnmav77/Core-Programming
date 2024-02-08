#include <iostream>

template<typename T>
class MyClass {
private:
    T privateMember;

public:
    MyClass(T privateVal) : privateMember(privateVal) {}

    template<typename U>
    friend void friendFunction(MyClass<U> obj);
};

template<typename T>
void friendFunction(MyClass<T> obj) {
    std::cout << "Accessing private member through friend function template: " << obj.privateMember << std::endl;
}

int main() {
    MyClass<int> obj(10);

    friendFunction(obj);

    return 0;
}
