#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T, int size>
class Solution {
    public: 
        T arr[size];
        Solution(T const a, T const b) {
            arr[0] = a;
            arr[1] = b;
        }   
        T solve() {
            return arr[0]+arr[1];
        }
};

int main()
{
    Solution <int , 5> s(1,2);
    cout<<s.solve();

    return 0;
}