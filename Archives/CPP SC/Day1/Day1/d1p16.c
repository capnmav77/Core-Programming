// I can change the pointers contents and change the pointer to point ot a different string
// if both are mutable
#include <stdio.h>

int main()
{
    char str[] = "Hello"; // a string variable
    char *p = str; // a pointer to the string
    printf("The string is %s\n", p); // print the string using the pointer
    p[0] = 'J'; // change the first character of the string using the pointer
    printf("The string is %s\n", p); // print the modified string using the pointer
    p = "World"; // change the pointer to point to another string literal
    printf("The string is %s\n", p); // print the new string using the pointer
    return 0;
}

/*const char* is a mutable pointer to an immutable character/string. This means that the pointer can point to 
any character or string variable or literal, 
but the value of that variable or literal cannot be changed through the pointer. For example: */

#include <stdio.h>

int main()
{
    char str[] = "Hello"; // a string variable
    const char *p = str; // a pointer to the string // the pointer is immutable but the contents of the array to which it's pointing is mutable.
    printf("The string is %s\n", p); // print the string using the pointer
    //p[0] = 'J'; // error: assignment of read-only location '*p'
    //printf("The string is %s\n", p); // this line will not execute
    p = "World"; // change the pointer to point to another string literal
    printf("The string is %s\n", p); // print the new string using the pointer
    return 0;
}

/* char* const is an immutable pointer to a mutable character/string. This means that the pointer cannot point to 
any other character or string variable or literal,
but the value of that variable or literal can be changed through the pointer. For example: */

#include <stdio.h>

int main()
{
    char str[] = "Hello"; // a string variable
    char * const p = str; // a pointer to the string
    printf("The string is %s\n", p); // print the string using the pointer
    p[0] = 'J'; // change the first character of the string using the pointer
    printf("The string is %s\n", p); // print the modified string using the pointer
    //p = "World"; // error: assignment of read-only variable 'p'
    //printf("The string is %s\n", p); // this line will not execute
    return 0;
}

/* const char* const is an immutable pointer to an immutable character/string. 
This means that neither the pointer nor the value it points to can be changed. 
For example: */
#include <stdio.h>

int main()
{
    char str[] = "Hello"; // a string variable
    const char * const p = str; // a pointer to the string
    printf("The string is %s\n", p); // print the string using the pointer
    //p[0] = 'J'; // error: assignment of read-only location '*p'
    //printf("The string is %s\n", p); // this line will not execute
    //p = "World"; // error: assignment of read-only variable 'p'
    //printf("The string is %s\n", p); // this line will not execute
    return 0;
}





