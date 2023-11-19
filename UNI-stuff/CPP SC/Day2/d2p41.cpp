#include<iostream>
// A base class
class Shape {
public:
    Shape() { std::cout << "Hello\n";}
    // A virtual function
    virtual void draw() {
        std::cout << "Drawing a shape" <<std::endl;
    }
};

// A derived class
// The derived class overrides the base class function 
// That is is not possible in a constructor
class Circle : public Shape {
public:
    // An overriding function
    void draw() {
        std::cout << "Drawing a circle" ;
    }
};
int main()
{
    Circle c1;
    c1.draw();
}
