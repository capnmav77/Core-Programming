#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Solution {

public:
    T solve(T const a, T const b) {
        return a+b;
    }

    template<typename U> // the compiler automatically deduces the type of U //implicit type deduction
    U solve(U const a, U const b) {
        cout<<"Here"<<endl;
        return a+b;
    }
    template<typename R> // the compiler automatically deduces the type of U //implicit type deduction
    R soln(R const a, R const b, R const c);
};

template<typename T>
template<typename R> // the compiler automatically deduces the type of U //implicit type deduction*
R Solution<T>::soln(R const a, R const b, R  const c) {
    cout<<"Here"<<endl;
    return a+b+c;
}

int main()
{
    Solution<double> s;
    // cout<<s.solve(1,2)<<endl; // since we have specified the type of T as double, the compiler will deduce the type of a and b , and overload the function
    // cout<<s.solve(1.1,2.2)<<endl; // since it is a double , it is not overloaded

    // cout<<s.solve<int>(1,2)<<endl; // since we have specified the type of T as double, the compiler will deduce the type of a and b , and overload the function
    cout<<s.soln(1,2,3)<<endl;
    return 0;
}

// Output
// Here
// 3
// 3.3
// Here
// 3