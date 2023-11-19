#include <stdio.h>

void my_strcpy(char dest[], const char src[])
{
    // get the length of the source string
    int len = 0;
    while (src[len] != '\0')
    {
        len++;
    }
    // check if the destination array has enough space
    if (sizeof(dest) < len + 1)
    {
        printf("Error: destination array is too small\n");
        return;
    }
    // copy the source string into the destination array
    for (int i = 0; i <= len; i++)
    {
        dest[i] = src[i]; // copy one character using subscript notation
    }
}

int main()
{
    char str1[] = "Hello"; // source string
    char str2[10]; // destination array
    my_strcpy(str2, str1); // call the function
    printf("str1: %s\n", str1); // print the source string
    printf("str2: %s\n", str2); // print the copied array
    return 0;
}
