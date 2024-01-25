#include <typeinfo>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   // automatic variable
   auto b = 10;
   // auto b;
   auto fl = 3.24;

   cout << "The variable b is of type: " << typeid(b).name() << endl;
   cout << "The variable fl is of type: " << typeid(fl).name() << endl;
   return 0;
}
