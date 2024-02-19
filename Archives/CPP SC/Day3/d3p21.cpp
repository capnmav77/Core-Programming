#include <iostream>
using namespace std;

// operator overloading for type conversion
class Fraction {
  int num; // numerator
  int den; // denominator
public:
  Fraction(int n = 0, int d = 1) : num(n), den(d) {} // constructor with default arguments
  void display() { // display the fraction
    cout << num << "/" << den << endl;
  }
  operator double() { // overload conversion operator to double
    return (double)num / den; // return the fraction as a double value
  }
};

int main() {
  Fraction f(3,4); // create a fraction object with num = 3 and den = 4
  f.display(); // display the fraction
  double d = f; // convert the fraction to double using the conversion operator
  cout << d << endl; // display the double value
}
