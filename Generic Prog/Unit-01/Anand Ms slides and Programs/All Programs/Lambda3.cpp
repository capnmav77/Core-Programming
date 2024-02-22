// Lambda function with return values

#include<iostream>
using namespace std;

int main() {

  // lambda function with explicit return type 'double'
  // returns the sum or the average depending on operation
  auto operation = []  (int a, int b,  string op) -> float { // the return type is int we can also use auto to get the return type
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
  //get the type of the variable sum
  cout << "Type of sum = " << typeid(sum).name() << endl; //d for double 

  // find the average of num1 and num2
  auto avg = operation(num1, num2, "avg"); 
  cout << "Average = " << avg <<endl;
  //get the type of the variable avg
  cout << "Type of avg = " << typeid(avg).name() << endl; //d for double 

  return 0;
}