// Intrinsic properties of the overloaded operator cannot be changed
// Preserves arity
// Preserves precedence
// Preserves associativity

#include <iostream>
using namespace std;

class Complex {
  private:
    double re, im;
  public:
    // Constructor
    Complex(double r = 0, double i = 0) {
      re = r;
      im = i;
    }

    // Overloading unary minus operator
    Complex operator-() const {
      return Complex(-re, -im);
    }

    // Overloading binary plus operator
    Complex operator+(const Complex& c) const {
      return Complex(re + c.re, im + c.im);
    }

    // Overloading binary multiplication operator
    Complex operator*(const Complex& c) const {
      return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // Display the complex number
    void show() const {
      cout << re << " + " << im << "i" << endl;
    }
};

int main() {
  // Create three complex numbers
  Complex c1(2, 3);
  Complex c2(4, 5);
  Complex c3(6, 7);

  // Display the complex numbers
  cout << "c1: ";
  c1.show();
  cout << "c2: ";
  c2.show();
  cout << "c3: ";
  c3.show();

  // Apply unary minus operator on c1
  cout << "-c1: ";
  (-c1).show(); // calls operator-()

  // Apply binary plus operator on c1 and c2
  cout << "c1 + c2: ";
  (c1 + c2).show(); // calls operator+()

  // Apply binary multiplication operator on c1 and c2
  cout << "c1 * c2: ";
  (c1 * c2).show(); // calls operator*()

  // Apply multiple operators on c1, c2 and c3
  cout << "-c1 + c2 * c3: ";
  (-c1 + c2 * c3).show(); // calls operator-(), operator*() and operator+()

  return 0;
}
