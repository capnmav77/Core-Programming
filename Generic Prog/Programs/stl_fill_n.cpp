// fill_n example
#include <iostream>     // std::cout
#include <algorithm>    // std::fill_n
#include <vector>       // std::vector

int main (void) {
  std::vector<int> myvector (8,10);        // myvector: 10 10 10 10 10 10 10 10

  std::fill_n (myvector.begin(),4,20);     // myvector: 20 20 20 20 10 10 10 10
  std::fill_n (myvector.begin()+3,3,33);   // myvector: 20 20 20 33 33 33 10 10

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}