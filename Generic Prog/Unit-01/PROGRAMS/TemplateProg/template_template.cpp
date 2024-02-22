#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename T>
class simple_wrapper
{
    public: 
        T helo(){
            return 1;
        }
}

template<typename T, template<typename> class Wrapper>
class Solution {
    public: 
        Wrapper<T> w;
        T solve() {
            return w.helo();
        }
};



int main()
{
    
    Solution <int , simple_wrapper> s;
    cout<<s.solve();
    return 0;
}