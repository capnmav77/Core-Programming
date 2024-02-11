#include<bits/stdc++.h>
using namespace std;

class student {
  public:
    // static variable 
    static int passing_marks;
};

int student::passing_marks = 33;

int main() 
{
  // definining object of the class student
  student s1, s2;
  s1.passing_marks = 40;
  cout << s2.passing_marks;

  return 0;
}
