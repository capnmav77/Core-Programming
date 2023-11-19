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

    Box* operator->() {
        return ptr;
    }
};

class BoxPointerWrapper {
    BoxPointer bp;
public:
    BoxPointerWrapper(Box* p = nullptr) : bp(p) {}

    // Overloading operator-> to return an object for which operator-> is in turn overloaded
    BoxPointer& operator->() {
        // This returns a BoxPointer object, which has its own operator-> overloaded
        // The returned object's operator-> will be called next
        return bp;
    }
};

int main() {
    Box b;
    BoxPointerWrapper pbw(&b);

    // Here, pbw.operator->() is called, which returns a BoxPointer
    // Then BoxPointer::operator->() is called, which returns a pointer to b
    // Finally, ->display() is called on that pointer, thus calling Box::display()
    pbw->display();

    return 0;
}
