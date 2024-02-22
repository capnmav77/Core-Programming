#include <iostream>
using namespace std;

class NotOp {
   private:
    int a;
    bool b;

   public:
    NotOp() : a(0), b(true) {}

    void in() {
        cout << "Enter the first number : ";
        cin >> a;
        cout<< "Enter true or false : ";
        cin >> b;
    }

    // Overloading the NOT (!)  operator
    void operator ! () {
        a= !a;
        b= !b;
    }

    void out() {
      cout<<"Output: "<<endl<< a<<endl<<b;
    }
};

int main() {
    NotOp obj;
    !obj;
    obj.out();

    return 0;
}