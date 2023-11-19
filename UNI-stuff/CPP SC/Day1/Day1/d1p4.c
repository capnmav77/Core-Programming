#include <stdio.h>

int main()
{
    int a, c = 5, d; // 
    a = (c++, c + 1); //
    d = sizeof(a); // assign d to the size of a in bytes using sizeof operator
    printf("a = %d\n", a); // print the value of a
    printf("c = %d\n", c); // print the value of c
    printf("d = %d\n", d); // print the value of d
    return 0;
}
