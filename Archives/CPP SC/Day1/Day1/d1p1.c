#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1; i>=0; i--)
    {
        for (j=7; j>=0; j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
    char c = 'A'; // ASCII value of 'A' is 65
    float f = 0.0f;

    // Print binary representation of c
    printf("Binary representation of c: ");
    printBits(sizeof(c), &c);

    // Convert 'c' to float by simple assignment
    f = c;

    // Print binary representation of f
    printf("Binary representation of f: ");
    printBits(sizeof(f), &f);

    // Print decimal representation of f
    printf("Decimal representation of f: %f\n", f);

    return 0;
}
