// Sample Program demonstrating the use of real() and imag() function
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	const int dmv = 17; // dmv is a named constant
    int var = 17; // var is not a constant
    constexpr double max1 = 1.4 * sqrt(dmv); // OK if square(17) is a constant expression because dmv is a named constant
   // constexpr double max2 = 1.4 * sqrt(var); // error : var is not a constant expression because it is not a named constant
    const double max3 = 1.4 * sqrt(var); // OK, may be evaluated at run time
    // the difference between const and constexpr is that constexpr must be evaluated at compile time and const can be evaluated at run time
    // constexpr is used to define constants that must be evaluated at compile time
    // const is used to define constants that can be evaluated at run time
    cout << max1 << endl;
   // cout << max2 << endl;
    cout << max3 << endl;


	return 0;
}
