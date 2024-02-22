// Program to demonstrate the use of Copy Assignment Operator

#include <iostream>

using namespace std;

class point
{
public:
	point ();
	~point ();
	point &operator=(const point &rhs);
	void SetPoint (const int _x, const int _y);
	void PrintPoint ();
	point (const point& obj)  // The copy constructor
	{
      		cout<<"Copy constructor is called"<<endl;
		*x = *(obj.x);
      		*y = *(obj.y);
	}
private:
	int *x;
	int *y;
};

point::point () // this is the default constructor of the class point and deep copy as we have constructed the values in the default constructor
{
	this->x = new int; // this is used to access the members of the class. 'this' is a pointer to the object whose member function is being executed
	*(this->x) = 0;
	this->y = new int;
	*(this->y) = 0;
	return;
}



point::~point()
{
	if (this->x != 0)
		delete this->x;
	if (this->y != 0)
		delete this->y;
	return;
}

point &point::operator=(const point &rhs) // The copy assignment operator is called when an already initialized object is assigned a new value from another already initialized object
{
	cout << "Copy assignment called" << endl; // this is shallow copy as we have constructed the values in the main function and not in the copy assignment operator
	(*this->x) = (*rhs.x);
	(*this->y) = (*rhs.y);
	return *this;
}



void point::SetPoint (const int _x, const int _y) // this is the member function of the class point and deep copy as we have constructed the values in the member function
{
	*(this->x) = _x;
	*(this->y) = _y;
	return;
}

void point::PrintPoint()
{
	cout << "(" << *(this->x) << ", " << *(this->y) << ") " << endl;
	return;
}

int main ()
{
	point p1, p2; //we have created the values here
	p1.SetPoint (61,65); // we have set the values here which is a deep copy
	p2 = p1; //shallow copy as we have constructed the values in the main function
        cout << "Before p3 " << endl;
    point p3 = p2; //copy constructor is called . Deep copy as we have constructed the values in the copy constructor
	p1.SetPoint (97, 98); // we have set the values here which is a deep copy because we have constructed the values in the member function
	p1.PrintPoint();
	p2.PrintPoint();
	return 0;
}

// once we construct the point using the point constructor , will it always be a deep copy?
// yes, because we have constructed the values in the default constructor
// once we construct the point using the copy constructor , will it always be a deep copy?
// yes, because we have constructed the values in the copy constructor
// once we construct the point using the copy assignment operator , will it always be a deep copy?
// no, because we have constructed the values in the main function and not in the copy assignment operator