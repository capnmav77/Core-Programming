#include <stdio.h>

int main (int argc, char **argv)
{
    char arr [20];
    int iarr [20];
    long larr [40];
    const char hex_array [] = {'A', 'B'};
    char *ptr = "PES University";

    printf ("size of char is %d\n", sizeof (char));
    printf ("size of short is %d\n", sizeof (short));
    printf ("size of int is %d\n", sizeof (int));
    printf ("size of long is %d\n", sizeof (long));
    printf ("size of float is %d\n", sizeof (float));
    printf ("size of double is %d\n", sizeof (double));

    printf ("1 is %d\n", sizeof (arr));
    printf ("2 is %d\n", sizeof (iarr));
    printf ("3 is %d\n", sizeof (larr));
    printf ("4 is %d\n", sizeof (hex_array));
    printf ("5 is %d\n", sizeof (ptr));
    return 0;
}
