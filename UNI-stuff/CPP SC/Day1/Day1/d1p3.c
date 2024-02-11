#include <stdio.h>

int main()
{
    int x = 10; // initialize x to 10
    int y = x++; // assign x to y and then increment x by 1
    int z = ++x; // increment x by 1 and then assign it to z
    printf("x = %d\n", x); // print the value of x
    printf("y = %d\n", y); // print the value of y
    printf("z = %d\n", z); // print the value of z
    return 0;
}
