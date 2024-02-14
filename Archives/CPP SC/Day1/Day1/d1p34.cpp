#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 20;

    // declare a lambda function that captures x by value and y by reference
    auto f = [x, &y]() {
        cout << "x = " << x << ", y = " << y << endl;
        // modify y inside the lambda
        y++;
    };

    // call the lambda function
    f(); // output: x = 10, y = 20

    // modify x and y outside the lambda
    x++;
    y++;

    // call the lambda function again
    f(); // output: x = 10, y = 22

    return 0;
}
