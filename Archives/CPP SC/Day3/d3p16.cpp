#include <iostream>

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the '==' operator
    bool operator==(const Point& p) {
        return x == p.x && y == p.y;
    }

    // Just a helper method to print the Point
    void displayPoint() {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(10, 20);
    Point p2(10, 20);
    Point p3(15, 25);

    if (p1 == p2) {
        std::cout << "Point p1 and Point p2 are the same: ";
        p1.displayPoint();
    } else {
        std::cout << "Point p1 and Point p2 are different.\n";
    }

    if (p1 == p3) {
        std::cout << "Point p1 and Point p3 are the same: ";
        p1.displayPoint();
    } else {
        std::cout << "Point p1 and Point p3 are different.\n";
    }

    return 0;
}
