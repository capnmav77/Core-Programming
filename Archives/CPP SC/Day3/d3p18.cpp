#include <iostream>

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point& operator++() {
        ++x;
        return *this;
    }

    Point operator++(int) {
        Point temp = *this;
        ++y;
        return temp;
    }

    void displayPoint() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(10, 20);

    std::cout << "Original Point: ";
    p1.displayPoint();

    Point p2 = ++p1; // Prefix increment
    std::cout << "After Prefix Increment: ";
    p1.displayPoint();
    std::cout << "State of p2 after Prefix Increment: ";
    p2.displayPoint();

    Point p3 = p1++; // Postfix increment
    std::cout << "After Postfix Increment: ";
    p1.displayPoint();
    std::cout << "State of p3 after Postfix Increment: ";
    p3.displayPoint();

    return 0;
}
