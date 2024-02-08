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
    A ob2 = ob1;                                    
    cout << "x = " << ob2.getX() << " y = " << ob2.getY();
    return 0;
}