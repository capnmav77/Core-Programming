#include <iostream>
using namespace std;

template <typename T>
int multiplication(T a, T b){
    return a*b;
}


int main()
{
    cout<<multiplication()<<endl;
}