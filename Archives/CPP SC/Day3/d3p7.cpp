#include <iostream>

class Box {
    int length;
public:
    Box(int l) : length(l) {}
    
    // '+' operator overloaded using a member function
    Box operator+(const Box& b) {
        return Box(this->length + b.length);
    }

    int getLength() {
        return length;
    }
};

int main() {
    Box box1(10);
    Box box2(20);

    // This calls "operator+" for "box1" and passes "box2" as an argument
    Box box3 = box1 + box2; 

    std::cout << "Length of Box3 : " << box3.getLength() << std::endl;

    return 0;
}
