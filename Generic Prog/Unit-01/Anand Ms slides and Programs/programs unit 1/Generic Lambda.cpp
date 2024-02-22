#include <iostream>
#include <string>
using namespace std;
main() 
{
   auto add = [](auto arg1, auto arg2) 
   {
      //define generalized lambda
      return arg1 + arg2;
   };
   cout << "Sum of integers: " << add(5, 8) << endl;
   cout << "Sum of floats: " << add(2.75, 5.639) << endl;
   cout << "Concatenate Strings: " << add(string("Hello "), string("World")) << endl;
}