#include<iostream>
#include<string>
// A class to represent a shape
class Shape {
    public:
    std::string color; // A string member

    // Default constructor
    Shape() : color("white") {
        std::cout << "Default constructor of Shape class called" << std::endl;
    }

    // Constructor with parameter
    Shape(std::string c) : color(c) {
        std::cout << "Constructor with parameter of Shape class called" << std::endl;
    }

    // Copy constructor
    Shape(const Shape& s) {
        color = s.color;
        std::cout << "Copy constructor of Shape class called" << std::endl;
    }

    // Assignment operator
    Shape& operator=(const Shape& s) {
        if (this != &s) { // Avoid self-assignment
            color = s.color;
            std::cout << "Assignment operator of Shape class called" << std::endl;
        }
        return *this;
    }
};

// A class to represent a circle that inherits from shape
class Circle : public Shape {
    public:
    double radius; // A double member

    // Constructor with parameters
    Circle(std::string c, double r) : Shape(c), radius(r) {
        std::cout << "Constructor with parameters of Circle class called" << std::endl;
    }

    // Copy constructor without chaining the base class
    Circle(const Circle& c) {
        radius = c.radius;
        // No call to the base class copy constructor
        std::cout << "Copy constructor of Circle class called" << std::endl;
    }

    // Assignment operator
    Circle& operator=(const Circle& c) {
        if (this != &c) { // Avoid self-assignment
            Shape::operator=(c); // Call the base class assignment operator
            radius = c.radius;
            std::cout << "Assignment operator of Circle class called" << std::endl;
        }
        return *this;
    }
};

// Driver code to test the copy constructor without chaining the base class
int main() {
    Circle c1("red", 10); // Create a circle object

    Circle c2(c1); // Copy construct another circle object from c1

    std::cout << "c1: color = " << c1.color << ", radius = " << c1.radius << std::endl;
    std::cout << "c2: color = " << c2.color << ", radius = " << c2.radius << std::endl;

    return 0;
}
