#include <iostream>
using namespace std;

class Counter {

  int count; // normal member variable
  public:
  static int total; // static member variable

  Counter(int c = 0) : count(c) { // constructor with default argument
    total += c; // increment total by count
  }
  void display() { // display count and total
    cout << "Count: " << count << ", Total: " << total << endl;
  }
};

// define and initialize static member variable outside the class
int Counter::total = 0;

int main() {
  Counter c1(5); // create a counter object with count = 5
  c1.display(); // display count and total

  Counter c2(10); // create another counter object with count = 10
  c2.display(); // display count and total

  // access static member variable using class name and scope resolution operator
  cout << "Total: " << Counter::total << endl;

  // access static member variable using an object and dot operator
  cout << "Total: " << c1.total << endl;

  // access static member variable using a pointer to an object and arrow operator
  Counter* ptr = &c2;
  cout << "Total: " << ptr->total << endl;
}
