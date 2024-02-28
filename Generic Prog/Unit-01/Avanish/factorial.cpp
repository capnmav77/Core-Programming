#include<iostream>

using namespace std;

template <typename T>
long long factorial(T n)
{
    if(n<=0)
    return 1;

    return n * factorial<T>(n-1);
}

template<>
long long factorial<char>(char x)
{
    if(x<'0' || x>'9')
    return 0;

    if(x=='0')
    return 1;

    return (x - '0') * factorial<char>(x-1);

}



int main()
{
    cout<<factorial<char>('5')<<endl;
}