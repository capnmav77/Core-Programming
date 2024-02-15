#include <iostream>
using namespace std;

class Complex {
  double re; // real part
  double im; // imaginary part
public:
  Complex(double r = 0, double i = 0) : re(r), im(i) {} // constructor with default arguments
  void display() { // display the complex number
    cout << re << "+" << im << "i" << endl;
  }
  friend Complex operator+(const Complex&, const Complex&); // declare friend function for operator+
};

Complex operator+(const Complex& c1, const Complex& c2) { // define friend function for operator+
  Complex sum; // create a new complex object to store the sum
  sum.re = c1.re + c2.re; // add the real parts
  sum.im = c1.im + c2.im; // add the imaginary parts
  return sum; // return the sum object
}

int main() {
  Complex c1(2,3); // create a complex object with re = 2 and im = 3
  Complex c2(4,5); // create another complex object with re = 4 and im = 5
  cout << "c1: "; 
  c1.display(); // display c1
  cout << "c2: ";
  c2.display(); // display c2
  cout << "c1 + c2: ";
  (c1 + c2).display(); // display c1 + c2 using operator+
  cout << "c1 + 10: ";
  (c1 + 10).display(); // display c1 + 10 using operator+
  cout << "10 + c2: ";
  (10 + c2).display(); // display 10 + c2 using operator+
}
