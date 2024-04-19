#include <algorithm>
#include <iostream>
using namespace std;
 
bool comp(int a, int b) 
{ 
  return (a < b); 
}

int main(){
    cout << std::max('a', 1) << "\n";

    cout << std::max(7, 7)<<endl;;

    //using pre-defined function
    int a = 9; 
    int b = 28; 
    cout << std::max(a,b,comp) << "\n"; 

    //max element in a list
    cout << std::max({1, 2, 3, 4, 5, 10, -1, 7},comp) << "\n"; //O(n)
    return 0;
}