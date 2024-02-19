#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // declare an integer variable
    int x;

    // set the flags for cin to read hexadecimal numbers
    cin.setf(ios::hex, ios::basefield);

    // set the fill character for cin to '_'
    cin.fill('_');

    // set the width for cin to 8
    cin.width(8);

    // read a hexadecimal number from the input
    cin >> x;

    // print the number in decimal format
    cout << dec << x << endl;

    return 0;
}
