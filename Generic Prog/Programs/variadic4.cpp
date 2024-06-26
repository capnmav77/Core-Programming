// Implementation of variable arguments using variadic templates.
#include <iostream>
using namespace std;

template <typename T>
void printDeveloperData(T t) {
    cout << t << '\n' ;
}

template<typename T, typename... Args>
void printDeveloperData(T t, Args... args) {
    cout << t << '\n';
    printDeveloperData(args...) ;
}

int main() {
    printDeveloperData("Bjarne", 20, 94.7);
}
