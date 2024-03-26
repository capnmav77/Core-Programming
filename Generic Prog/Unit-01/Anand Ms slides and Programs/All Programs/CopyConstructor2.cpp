#include <iostream>  
using namespace std;  
class Example  
{  
   public:  
    int a;  
    Example(int x)                // parameterized constructor  
    {  
      a=x;  
    }  
    Example(Example &ob)               // copy constructor  
    { 
	cout << "Copy constructor called" << endl; 
        a = ob.a;  
    }  
};  
int main()  
{  
  Example e1(36);               // Calling the parameterized constructor  which is a deep copy             //  Calling the copy constructor which is a deep copy
  Example e3 (12);        // Calling the parameterized constructor which is a deep copy
  e3 = e1;        // Calling the copy constructor which is a shallow copy? No, it is a deep copy why is it ? 
  cout<<e3.a;  
  return 0;  
}  