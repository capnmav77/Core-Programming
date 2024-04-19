// reverse_copy example
#include <iostream>     // std::cout
#include <algorithm>    // std::reverse_copy
#include <vector>       // std::vector

int main (void) {
  int myints[] ={1,2,3,4,5,6,7,8,9};
  std::vector<int> myvector;

  myvector.resize(9);    // allocate space

  std::reverse_copy (myints, myints+9, myvector.begin());

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}