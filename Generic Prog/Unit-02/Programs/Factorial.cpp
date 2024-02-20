#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
private:

public:
    template <typename T> // T is the CI for int and T* is the CI for int*
    int Factorial(const T &val) {
        if(static_cast<T>(val) == 0) {
            return 1;
        }
        //recursive call for T-1
        return static_cast<T>(val) * Factorial(static_cast<T>(val-1));
    }
};


int main()
{
    Solution s;
    cout<<s.Factorial(5);
    return 0;
}