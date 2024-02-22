#include<bits/stdc++.h>

using namespace std;


class SmartPointer
{
    int *ptr; //actual pointer

public:
    //constructor
    explicit SmartPointer(int *p = NULL) { cout<<"init the pointer"; ptr = p; }

    //destructor
    ~SmartPointer() { cout<<"deleting the pointer"; delete (ptr); }

    //overloading dereferencing operator
    int &operator*() { return *ptr; }
};

int main()
{
    SmartPointer ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}