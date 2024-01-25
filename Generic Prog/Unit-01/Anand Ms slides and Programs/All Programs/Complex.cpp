// Sample Program demonstrating the use of real() and imag() function
#include <iostream>

#include <complex>
using namespace std;

int main()
{
	// defines the complex number: (10 + 2i)
	complex<double> mycomplex(10.0, 2.0);
	complex <int> ComplexInt (6, 4);

	cout << "For the complex number mycomplex: " << endl;
	cout << "Real part: " << real(mycomplex) << endl;
	cout << "Imaginary part: " << imag(mycomplex) << endl;
	// prints the absolute value of the complex number
  	cout << "The absolute value of " << mycomplex << " is: ";
  	cout << abs(mycomplex) << endl;

  	cout << "For the complex number ComplexInt: " << endl;
	cout << "Real part: " << real(ComplexInt) << endl;
	cout << "Imaginary part: " << imag(ComplexInt) << endl;
	// prints the absolute value of the complex number
  	cout << "The absolute value of " << ComplexInt << " is: ";
  	cout << abs(ComplexInt) << endl;

	return 0;
}
