#include <iostream>

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend std::istream& operator>>(std::istream& in, Point& p);
};

// Overloading the insertion operator
std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.x << ", " << p.y << ")";
    return out;
}

// Overloading the extraction operator
std::istream& operator>>(std::istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    Point p1;

    std::cout << "Enter x and y for point p1: ";
    std::cin >> p1;

    std::cout << "You entered " << p1 << std::endl;

    return 0;
}
