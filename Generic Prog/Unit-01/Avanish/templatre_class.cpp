#include<iostream>

using namespace std;

template <typename T>
struct foo{
    // protected: using value_type = T;
    using value_type = T;
};


template <typename T, typename U=typename T::value_type>
struct bar{
    using value_type =U;
};


int main()
{
    bar<foo<int>> x;
    return 0;
}