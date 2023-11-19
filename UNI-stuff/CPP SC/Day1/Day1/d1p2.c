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
    double d = 21.021;
    char c1, c2;

    // Without typecasting
    c1 = d;
    printf("Without typecasting:\n");
    printf("Decimal representation of c1: %d\n", c1);
    printf("Binary representation of c1: ");
    printBits(sizeof(c1), &c1);

    // With typecasting
    c2 = (char)d;
    printf("\nWith typecasting:\n");
    printf("Decimal representation of c2: %d\n", c2);
    printf("Binary representation of c2: ");
    printBits(sizeof(c2), &c2);

    return 0;
}
