#include<iostream>
#include<string>
// A class to represent a shape
class Shape {
    public:
    std::string color; // A string member

    // Constructor
    Shape(std::string c) : color(c) {}

    // Copy constructor
    Shape(const Shape& s) {
        color = s.color;
    }

    // Assignment operator
    Shape& operator=(const Shape& s) {
        if (this != &s) { // Avoid self-assignment
            color = s.color;
        }
        return *this;
    }
};

// A class to represent a circle that inherits from shape
class Circle : public Shape {
    public:
    double radius; // A double member

    // Constructor
    Circle(std::string c, double r) : Shape(c), radius(r) {}

    // Copy constructor with chaining the base class
    Circle(const Circle& c) : Shape(c) { // Call the constructor of the base class using initialization list syntax
        radius = c.radius;
        
    }

    // Assignment operator
    Circle& operator=(const Circle& c) {
        if (this != &c) { // Avoid self-assignment
            Shape::operator=(c); // Call the base class assignment operator
            radius = c.radius;
        }
        return *this;
    }
};

// Driver code to test the copy constructor with chaining the base class
int main() {
    Circle c1("red", 10); // Create a circle object

    Circle c2(c1); // Copy construct another circle object from c1

    std::cout << "c1: color = " << c1.color << ", radius = " << c1.radius << std::endl;
    std::cout << "c2: color = " << c2.color << ", radius = " << c2.radius << std::endl;

    return 0;
}
