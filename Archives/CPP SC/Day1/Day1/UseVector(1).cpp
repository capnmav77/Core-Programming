// Program to demonstrate the use of vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> nums;
   int temp;

   for (int i = 0; i < 10; i ++)
   {
       cout << "Key in the number:";
       cin >> temp;
       nums.push_back (temp);
   }

   cout << "Size of vector is " << nums.size() << endl;
   for(int num: nums)
      cout << num << " ";
}
