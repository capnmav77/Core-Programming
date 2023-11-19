#include <iostream>

// Base class
class Animal {
public:
    int legs;
    void eat() {
        std::cout << "I can eat!" << std::endl;
    }

    virtual void speak() {
        std::cout << "The animal makes a sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.legs = 4;
    myDog.eat();    // Inherited from Animal
    myDog.speak();  // Overridden in Dog
    std::cout << myDog.legs;
    return 0;
}
