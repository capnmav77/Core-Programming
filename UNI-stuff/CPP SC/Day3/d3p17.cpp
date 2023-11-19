#include <iostream>

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Prefix increment operator
    Point& operator++() {
        ++x;    // Increment x before returning. This is the usual behavior of the prefix increment.
        return *this; // Return a reference to the current object for possible chaining of operations.
    }

    // Postfix increment operator
    Point operator++(int) {
        // The int parameter is a convention to differentiate between prefix and postfix increment. 
        // It's not used in the function itself.
        
        Point temp = *this; // Create a copy of the current state of the object.
        
        ++y;    // Increment y after returning. This is the usual behavior of the postfix increment.

        return temp; // Return the original state before the increment.
    }

    void displayPoint() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(10, 20);

    std::cout << "Original Point: ";
    p1.displayPoint();

    // Prefix increment
    ++p1; // This will increment p1's x and the incremented p1 is used for the next operation.
    std::cout << "After Prefix Increment: ";
    p1.displayPoint();

    // Postfix increment
    p1++; // This will increment p1's y, but the original p1 is used for the next operation.
    std::cout << "After Postfix Increment: ";
    p1.displayPoint();

    return 0;
}
