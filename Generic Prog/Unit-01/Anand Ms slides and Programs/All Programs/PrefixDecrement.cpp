#include <iostream>
using namespace std;

class OverLoad {
   private:
    int a;
    int b;

   public:
    OverLoad() : a(0), b(0) {}

    void in() {
        cout << "Enter the first number : ";
        cin >> a;
        cout<< "Enter the second number : ";
        cin >> b;
    }

    // Overload the prefix decrement operator
    void operator-- () {
        a= --a;
        b= --b;
    }

    void out() {
      cout<<"The decremented elements of the object are:  "<<endl<< a<<" and " <<b;
    }
};

int main() {
    OverLoad obj;
    obj.in();
    --obj;
    obj.out();

    return 0;
}
