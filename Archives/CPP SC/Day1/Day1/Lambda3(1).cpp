// Lambda function with return values

#include<iostream>
using namespace std;

int main() {

  // lambda function with explicit return type 'double'
  // returns the sum or the average depending on operation
  auto operation = []  (int a, int b,  string op) -> double {
    if (op == "sum") {
      return a + b;
    }
    else {
      return (a + b) / 2.0;
    }
  };

  int num1 = 1;
  int num2 = 2;

  // find the sum of num1 and num2
  auto sum = operation(num1, num2, "sum"); 
  cout << "Sum = " << sum << endl;

  // find the average of num1 and num2
  auto avg = operation(num1, num2, "avg"); 
  cout << "Average = " << avg;

  return 0;
}