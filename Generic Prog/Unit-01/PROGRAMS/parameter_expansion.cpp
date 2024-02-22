#include<iostream>

using namespace std;

template<class... I>
void func(I... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}

int main()
{
    func("Hello", 1, 2.0002, '$');
    return 0;
}
