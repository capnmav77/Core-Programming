// C++ program to demonstrate the use of class templates

#include <iostream>
using namespace std;

// Class template
template <typename T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor 
    //why dont' we manually define the constructor?
    //because we are using a template class, so we don't know the type of the variable
    //so we can't define the constructor manually
    // what about num = n;?
    // num(n) is the same as num = n;

    T getNum() {
        return num;
    }
};

int main() {

    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}