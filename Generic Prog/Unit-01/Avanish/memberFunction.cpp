#include<iostream>

using namespace std;


template <typename T>
class Comp{

public:
    T add(T a,T b)
    {
        cout<<"Here"<<endl;
        return a+b;
    }

    template <typename U>
    T add(U a,U b)
    {
        return a+b;
    }

    template <typename K>
    T sub(K a,K b);
};


template <typename T>
template <typename K>
T Comp<T>::sub(K a, K b)
{
    return b-a;
}


int main()
{
    Comp<int> A;

    cout<<A.add<int>(4,5)<<endl;


}