/*A void pointer in C is a pointer that does not have any associated data type.
It can point to any memory location, regardless of the type of data stored there.
A void pointer can be typecasted to any other pointer type when needed.

For example, consider this code: */

#include <stdio.h>

int main()
{
    int x = 10; // an integer variable
    char y = 'A'; // a character variable
    void *p; // a void pointer
    p = &x; // assign the address of x to p
    printf("The value of x is %d\n", *(int *)p); // print the value of x by typecasting p to int *
    p = &y; // assign the address of y to p
    printf("The value of y is %c\n", *(char *)p); // print the value of y by typecasting p to char *
    return 0;
}
