//pureVirtual_ABC.cpp
//Program demonstrates pure virtual function (Virtual function equated to zero) and 
//Abstract Base Class(Class which has a pure virtual function). 
//Abstract Base Class is not instantiable.
//Pgm also demonstrates hierarchial inheritance (2 or more derived classes deriving from the same base class)
#include<iostream>

using namespace std;

class Shape
{
	public:virtual void area()=0;
};
//To show that pure virtual function may have a body. But it has to be defined outside the class.
//void Shape::area(){cout<<"Body"<<endl;}		
class Rectangle:public Shape
{
	double ml,mb;	
	public: Rectangle(double l=0,double b=0){ml=l;mb=b;}
		void area(){cout<<"Rectangle Area="<<ml*mb<<endl;}
	
};

class Circle:public Shape
{
	double pi;
	double mr;
	public: Circle(double r=0){mr=r; pi=3.142;}
		void area(){cout<<"Circle Area="<<pi*mr*mr<<endl;}
};
int main()
{
	//Below line is an error. BecauseShape is an Abstract Base Class(ABC) and hence not instantiable.
//	Shape s;
	
	Rectangle r(2,3);
	r.area();

	Circle c(2);
	c.area();
	
	//Calling Base class area by an object of derived class. Uncomment the body of Shape::area to not get linker error
//	r.Shape::area();

	return 0;	
}

/*
Output:
Rectangle Area=6
Circle Area=12.568
*/
