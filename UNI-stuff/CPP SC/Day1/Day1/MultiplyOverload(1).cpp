// Multiplication of two fractions
#include <iostream>
using namespace std;

class Frac {
   private:
    int a;
    int b;

   public:
    Frac() : a(0), b(0) {}

    void in() {
        cout << "Enter the numerator : ";
        cin >> a;
        cout<< "Enter the denominator : ";
        cin >> b;
    }

    // Overload the * operator
    Frac operator * (const Frac &obj) {
        Frac temp;
        temp.a = a * obj.a;
        temp.b = b * obj.b;
       
        return temp;
    }

    void out() {
      cout<<"The fraction is  "<< a<<"/ "<<b;
    }
};

int main() 
{
    Frac F1, F2, result;

    cout << "Enter the first fraction:\n";
    F1.in();

    cout << "Enter the second fraction:\n";
    F2.in();

   // complex1 calls the operator function
   // complex2 is passed as an argument to the function
    result = F1 * F2;
    result.out();

    return 0;
}
