#include<iostream>

using namespace std;

// template <typename T>
// struct foo{
//     void f(){}
//     void g(){
//         int x="200";
//     }
// };

// int main()
// {
//     foo<int>* x;
//     foo<int> y;
//     foo<double>* q;
//     q->f();
// }

template <typename T>
struct foo{
    static T data;
};


template<typename T>T foo<T>::data = 0;

int main()
{
    foo<int> a;
    foo<double> b;
    foo<double> c;

    cout<<a.data<<endl;
    cout<<b.data<<endl;
    cout<<c.data<<endl;

    b.data = 42;

    cout<<a.data<<endl;
    cout<<b.data<<endl;
    cout<<c.data<<endl;
}