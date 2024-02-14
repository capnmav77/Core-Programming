#include <iostream>

class Box {
public:
    void display() {
        std::cout << "Display from Box object!" << std::endl;
    }
};

class BoxPointer {
    Box* ptr;
public:
    BoxPointer(Box* p = nullptr) : ptr(p) {}

    // Overloading operator-> to return a raw pointer
    Box* operator->() {
        // This returns a raw pointer to a Box
        return ptr;
    }
};

int main() {
    Box b;
    BoxPointer pb(&b);

    // Here, pb.operator->() is called, which returns a pointer to b
    // Then ->display() is called on that pointer, thus calling Box::display()
    pb->display();

    return 0;
}
