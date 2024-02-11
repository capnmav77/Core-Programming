#include <iostream>

class Box {
    int length;
public:
    Box(int l) : length(l) {}

    int getLength() {
        return length;
    }

    // Friend function declaration
    friend Box operator+(const Box& b1, const Box& b2);
};

// '+' operator overloaded using a friend function (non-member)
Box operator+(const Box& b1, const Box& b2) {
    return Box(b1.length + b2.length);
}

int main() {
    Box box1(10);
    Box box2(20);

    // This calls the global "operator+" and passes "box1" and "box2" as arguments
    Box box3 = box1 + box2; 

    std::cout << "Length of Box3 : " << box3.getLength() << std::endl;

    return 0;
}
