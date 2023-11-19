#include <stdio.h>

int main()
{
    unsigned int x = 4294967295; // the maximum value of unsigned int
    int y = (int)x; // explicitly convert x to int
    printf("x = %u\n", x); // print the value of x
    printf("y = %d\n", y); // print the value of y // dont move a unsigned int to a signed int 
    return 0;
}
