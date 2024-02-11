#include<iostream>
using namespace std;

class Point
{
	private:
	int x, y;
	public:
	Point() : x(0), y(0) { }
	Point& operator()(int dx, int dy);
	void show() {cout << "x = " << x << ", y = " << y; }
};

Point& Point::operator()(int dx, int dy)
{
	x = dx;
	y = dy;
	return *this;
}

int main()
{
	Point pt;
	pt(3, 2);
	pt.show();
	return 0;
}
