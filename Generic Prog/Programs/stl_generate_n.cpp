// generate_n example
#include <iostream>     // std::cout
#include <algorithm>    // std::generate_n

int current = 0;
int UniqueNumber () { return ++current; }

int main (void) {
  int myarray[9];

  std::generate_n (myarray, 9, UniqueNumber);

  std::cout << "myarray contains:";
  for (int i=0; i<9; ++i)
    std::cout << ' ' << myarray[i];
  std::cout << '\n';

  return 0;
}