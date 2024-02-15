#include <iostream>

class B;
class C;

class A {
public:
    void displayB(B& b); 
    void displayC(C& c); 
};

class B {
private:
    int privateDataB;

public:
    B() : privateDataB(10) {}

    friend void A::displayB(B& b); 
    friend class C; // B is now a friend of C
};

class C {
private:
    int privateDataC;

public:
    C() : privateDataC(20) {}

    void displayB(B& b); 
};

void A::displayB(B& b) {
    std::cout << "A can access B's private data: " << b.privateDataB << std::endl;
}

void A::displayC(C& c) {
    // This function is not able to access privateDataC of class C as A is not a friend of C
}

void C::displayB(B& b) {
    std::cout << "C can access B's private data: " << b.privateDataB << std::endl;
}

int main() {
    A a;
    B b;
    C c;

    a.displayB(b); 
    c.displayB(b); // Now, C can access B's private data

    return 0;
}
