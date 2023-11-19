#include <stdio.h>

int main(void)
{
    int x = 1; // a multibyte data type
    char *y = (char *)&x; // a pointer to the first byte of x
    if (*y == 1) // check the value of the first byte
    {
        printf("Little endian\n"); // if it is 1, then it is little endian
    }
    else
    {
        printf("Big endian\n"); // if it is not 1, then it is big endian
    }
    return 0;
}
