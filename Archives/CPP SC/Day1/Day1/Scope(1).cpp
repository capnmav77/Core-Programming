#include<bits/stdc++.h>
using namespace std;

// this is a global variable
int var = 20;

int main() 
{
  // this is a local varible
  // its scope is within main function only
  int x = 10;

  if (x <= 10) 
  {
    // here y is a local variable 
    // whose scope exists within this if block
    int y = 2;

    cout << x * y;
  }

  return 0;
}
