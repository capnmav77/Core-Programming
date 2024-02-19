// The C++ language requires some operators to be methods 
// of a class because they don’t make sense outside of a class. 
// For example, operator= is tied so 
// closely to the class that it can’t exist anywhere else.

#include <iostream>
using namespace std;

class Point {
  private:
    int x, y;
  public:
    // Constructor
    Point(int x = 0, int y = 0) {
      this->x = x;
      this->y = y;
    }

    // Overloading operator= method
    Point& operator=(const Point& p) {
      // Check for self-assignment
      if (this != &p) {
        // Copy the values
        this->x = p.x;
        this->y = p.y;
      }
      // Return the current object by reference
      return *this;
    }

    // Display the point
    void show() {
      cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
  // Create two points
  Point p1(10, 20);
  Point p2(30, 40);

  // Display the points
  cout << "Before assignment:" << endl;
  p1.show();
  p2.show();

  // Assign p2 to p1 using operator=
  p1 = p2;

  // Display the points again
  cout << "After assignment:" << endl;
  p1.show();
  p2.show();

  return 0;
}
