#include <stdio.h>

// A struct with a function pointer
typedef struct {
    int x; // 4 bytes
    double (*fp)(double); // 4 or 8 bytes (function pointer)
} A;

// A struct with an integer field
typedef struct {
    int x; // 4 bytes
} B;

double f(double d) { // no extra bytes (member function)
    return d; // The behavior in C isn't identical since we can't associate the function with an instance of the struct
}

int main() {
    printf("Size of A: %zu\n", sizeof(A)); // 8 or 12 bytes
    printf("Size of B: %zu\n", sizeof(B)); // 4 bytes
    return 0;
}
