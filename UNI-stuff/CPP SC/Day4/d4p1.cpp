#include<iostream>
// A class to store owner details
class OwnerDetails {
    public:
    std::string name;
    int age;
    OwnerDetails(std::string n, int a) : name(n), age(a) {} // Constructor
};

// A global function to print a message
void printMessage(std::string msg) {
    std::cout << msg << std::endl;
}

// A class to represent an animal
class Animal {
    public:
    int id; // A plain int member
    OwnerDetails* owner; // A pointer to another class
    void (*func)(std::string); // A function pointer

    // Constructor
    Animal(int i, OwnerDetails* o, void (*f)(std::string)) : id(i), owner(o), func(f) {}

    // Copy constructor
    Animal(const Animal& a) {
        id = a.id;
        owner = new OwnerDetails(a.owner->name, a.owner->age); // Deep copy of the pointer
        func = a.func;
    }

    // Assignment operator
    Animal& operator=(const Animal& a) {
        if (this != &a) { // Avoid self-assignment
            id = a.id;
            delete owner; // Free the old memory
            owner = new OwnerDetails(a.owner->name, a.owner->age); // Deep copy of the pointer
            func = a.func;
        }
        return *this;
    }

    // Destructor
    ~Animal() {
        delete owner; // Free the memory allocated for the pointer
    }
};

// A class to represent a dog that inherits from animal
class Dog : public Animal {
    public:
    std::string breed; // An additional member

    // Constructor
    Dog(int i, OwnerDetails* o, void (*f)(std::string), std::string b) : Animal(i, o, f), breed(b) {}

    // Copy constructor
    Dog(const Dog& d) : Animal(d), breed(d.breed) {}

    // Assignment operator
    Dog& operator=(const Dog& d) {
        if (this != &d) { // Avoid self-assignment
            Animal::operator=(d); // Call the base class assignment operator
            breed = d.breed;
        }
        return *this;
    }
};

// Driver code to test the copy constructor and assignment operator for dog class
int main() {
    OwnerDetails* o1 = new OwnerDetails("Alice", 25); // Create an owner object
    Dog d1(1, o1, printMessage, "Labrador"); // Create a dog object

    Dog d2(d1); // Copy construct another dog object from d1

    OwnerDetails* o2 = new OwnerDetails("Bob", 30); // Create another owner object
    Dog d3(2, o2, printMessage, "Poodle"); // Create another dog object

    d3 = d1; // Assign d1 to d3

    std::cout << "d1: id = " << d1.id << ", owner name = " << d1.owner->name << ", breed = " << d1.breed << std::endl;
    std::cout << "d2: id = " << d2.id << ", owner name = " << d2.owner->name << ", breed = " << d2.breed << std::endl;
    std::cout << "d3: id = " << d3.id << ", owner name = " << d3.owner->name << ", breed = " << d3.breed << std::endl;

    return 0;
}
