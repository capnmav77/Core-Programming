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

point::point ()
{
	this->x = new int;
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

point &point::operator=(const point &rhs)
{
	cout << "Copy assignment called" << endl;
	(*this->x) = (*rhs.x);
	(*this->y) = (*rhs.y);
	return *this;
}



void point::SetPoint (const int _x, const int _y)
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
	p1.SetPoint (61,65);
	p2 = p1; //shallow copy as we have constructed the values in the main function
        cout << "Before p3 " << endl;
        point p3 = p2; //copy constructor is called . Deep copy as we have constructed the values in the copy constructor
	p1.SetPoint (97, 98);
	p1.PrintPoint();
	p2.PrintPoint();
	return 0;
}
