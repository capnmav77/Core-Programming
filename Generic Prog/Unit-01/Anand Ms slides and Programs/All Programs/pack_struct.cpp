#include <iostream>

using namespace std;

int main(void)
{
    struct foo {
        char c;
        int x;
    }__attribute__((packed));

    cout << "Size is :" << sizeof (struct foo);
    return 0;
}
