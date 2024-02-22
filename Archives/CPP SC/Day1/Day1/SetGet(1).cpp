// Program to demonstrate how to access private members

#include <iostream>
using namespace std;

class Employee 
{
    // Private attribute
    int salary;

  public:
    // Setter
    void setSalary(int s) 
    {
      salary = s;
    }
    // Getter
    int getSalary() 
    {
      return salary;
    }
};

int main() 
{
  Employee myObj;
  // cout << myObj.salary;    // cannot access private members
  myObj.setSalary(50000);
  cout << myObj.getSalary();
  return 0;
}