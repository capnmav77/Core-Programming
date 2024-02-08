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
        a = ob.a;  
    }  
};  
int main()  
{  
  Example e1(36);               // Calling the parameterized constructor  
 Example e2(e1);                //  Calling the copy constructor  
 cout<<e2.a;  
  return 0;  
}  