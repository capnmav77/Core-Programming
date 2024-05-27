#include <iostream>
using namespace std;

class A {
    int x, y;
  
public:
    A(int i, int j)
    {
        x = i;
        y = j;
    }
    int getX() { return x; }
    int getY() { return y; }
};
  
int main()
{
    A ob1(10, 46);
    A ob2 = ob1;    //soft copy of ob1 to ob2 i.e. ob2 is a copy of ob1 which shares the same memory location as ob1 therefore , if we change the value of ob2 then the value of ob1 will also change
    cout << "x = " << ob1.getX() << " y = " << ob1.getY();
    //changing the value of ob2
    ob2 = A(20, 30);
    cout << endl;                                
    cout << "x = " << ob1.getX() << " y = " << ob1.getY();
    return 0;
}