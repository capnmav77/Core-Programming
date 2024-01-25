#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double number, squareRoot;

    cout << "Key in a number: ";
    cin >> number;
    // sqrt() is a library function to calculate the square root
    squareRoot = sqrt(number);

    cout << "Square root of " << number << " = " << squareRoot;

    return 0;
}
