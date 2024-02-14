#include<iostream>
#include<stdio.h>
using namespace std;
// A base class
class Shape {
public:
    // shape() { std::cout << "Hello";}
    // A virtual function
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

// A derived class
// The derived class overrides the base class function 
// That is is not possible in a constructor
class Circle : public Shape {
public:
    // An overriding function
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};
int main()
{
    Circle c1;
    // c1 = new Circle();
    c1.draw();
}
