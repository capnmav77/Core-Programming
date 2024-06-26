// Calculating the maximum of integers and floating numbers using variadic templates.
#include <iostream>
using namespace std;

double maxm = 0;

template <typename T>
void calculateMaximum(T t) {
    if (t > maxm) {
        maxm = t;
    }
    cout << maxm;
}

template<typename T, typename... Args>
void calculateMaximum(T t, Args... args) {
    if (t > maxm) {
        maxm = t;
    }
    calculateMaximum(args...) ;
}

int main() {
    calculateMaximum(12, 12.4, 27, 28.1, 27.9, 28, 23);
}
