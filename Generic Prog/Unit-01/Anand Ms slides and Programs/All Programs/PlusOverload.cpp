#include <iostream>
using namespace std;

class Time {
   private:
    int hour;
    int minute;

   public:
    Time() : hour(0), minute(0) {}

    void in() {
        cout << "Enter the time: ";
        cin >> hour;
        cin >> minute;
    }

    // Overload the + operator
    Time operator + (const Time & obj) {
        Time temp;
        temp.hour = hour + obj.hour;
        temp.minute = minute + obj.minute;
        if (temp.minute>=60)
        {
            temp.hour+=1;
            temp.minute-=60;
        }
        if (temp.hour>24)
        temp.hour=1;
        return temp;
    }

    void out() {
      cout<<"Time is "<< hour<<"hrs "<<minute<<"min";
    }
};

int main() {
    Time T1, T2, result;

    cout << "Enter first time in hours and minutes one by one :\n";
    T1.in();

    cout << "Enter second time in hours and minutes one by one :\n";
    T2.in();

   // T1 calls the operator function
   // T2 is passed as an argument to the function
    result = T1 + T2;
    result.out();

    return 0;
}
