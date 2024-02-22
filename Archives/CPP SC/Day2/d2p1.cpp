#include <iostream>
using namespace std;

// A structure with word alignment
// On a 32 bit machine the words are 4 bytes so the alignment is 4 bytes for each of these
// There reference for member functions are stored elsewhere
struct A {
    char c; // 1 byte
    int i; // 4 bytes
    short s; // 2 bytes
    
    int foo()
    {
        cout << "Hello";
        return 0;
    }
};

// A structure with packing
#pragma pack(1) // pack with 1 byte
struct B {
    char c; // 1 byte
    int i; // 4 bytes
    short s; // 2 bytes
};
#pragma pack()

int main() {
    cout << "Size of A: " << sizeof(A) << endl; // 12 bytes (4 + 4 + 4)
    cout << "Size of B: " << sizeof(B) << endl; // 7 bytes (1 + 4 + 2)
    return 0;
}
