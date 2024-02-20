#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<unsigned int N>
inline constexpr unsigned int Factorial() {return N * Factorial<N-1>();}

template<>
inline constexpr unsigned int Factorial() {return 1;}

int main()
{
    cout<<Factorial<5>();
    return 0;
}