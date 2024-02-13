#include<iostream>


using namespace std;

constexpr double PI = 3.1415926;


template <typename T>
T sphere_volume(T const r)
{
    return 4 * PI * r *r *r /3; 
}

int main()
{
    cout<<sphere_volume(3.249964846546456754f)<<endl;
}