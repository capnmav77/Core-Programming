// Sample program to demonstrate the use of user-defined functions
#include <iostream>
using namespace std;

// function declaration
int max(int num1, int num2);

int main ()
{
   // local variable declaration:
   int num1, num2;
   int ret;

   cout << "Key in two numbers: ";
   cin >> num1 >> num2;
   // calling a function to get max value.
   ret = max(num1, num2);
   cout << "Max value is : " << ret << endl;
   return 0;
}

// function returning the max between two numbers
int max(int num1, int num2)
{
   // local variable declaration
    int result;

    /*
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    */
    result = num1 > num2 ? num1: num2;
    return result;
}
