// remove_copy_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove_copy_if
#include <vector>       // std::vector

bool IsOdd (int i) { return ((i%2)==1); }

int main (void) {
  int myints[] = {1,2,3,4,5,6,7,8,9};
  std::vector<int> myvector (9);

  std::remove_copy_if (myints,myints+9,myvector.begin(),IsOdd);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}