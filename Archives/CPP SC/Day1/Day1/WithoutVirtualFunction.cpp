// C++ program to demonstrate how we will calculate area of shapes without virtual function
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
	// parameterized constructor
	Shape(int l, int w)
	{
		length = l;
		width = w;
	}
	int get_Area()
	{
		cout << "This is call to parent class area\n";
		// Returning 1 in user-defined function means true
		return 1;
	}

protected:
	int length, width;
};

// Derived class
class Square : public Shape {
public:
	Square(int l = 0, int w = 0)
		: Shape(l, w)
	{
	} // declaring and initializing derived class constructor
	int get_Area()
	{
		cout << "Square area: " << length * width << '\n';
		return (length * width);
	}
};
// Derived class
class Rectangle : public Shape {
public:
	Rectangle(int l = 0, int w = 0)
		: Shape(l, w)
	{
	} // declaring and initializing derived class constructor
	int get_Area()
	{
		cout << "Rectangle area: " << length * width
			<< '\n';
		return (length * width);
	}
};

int main()
{
	Shape* s;

	// Making object of child class Square
	Square sq(5, 5);

	// Making object of child class Rectangle
	Rectangle rec(4, 5);
	s = &sq; // reference variable
	s->get_Area();
	s = &rec; // reference variable
	s->get_Area();

	return 0; 
}
