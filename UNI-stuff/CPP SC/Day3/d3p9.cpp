#include <iostream>

class Box {
    int length;
public:
    Box(int l) : length(l) {}

    int getLength() {
        return length;
    }

    // Friend function declaration
    friend Box operator+(int lhs, const Box& rhs);
};

// '+' operator overloaded using a friend function to add an integer(a different data type  to a Box
Box operator+(int lhs, const Box& rhs) {
    return Box(lhs + rhs.length);
}

int main() {
    Box box1(10);
    int increment = 20;

    // This calls the global "operator+" and passes "increment" and "box1" as arguments
    Box box2 = increment + box1;

    std::cout << "Length of Box2 : " << box2.getLength() << std::endl;

    return 0;
}
