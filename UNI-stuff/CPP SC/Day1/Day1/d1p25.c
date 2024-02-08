#include <stdio.h>

int main(int argc, char *argv[])
{
    // check if the argument is given
    if (argc < 2)
    {
        printf("Usage: %s argument\n", argv[0]); // print the usage message
        return 1; // exit with an error code
    }
    // print the argument
    printf("%s\n", argv[1]); // print the first argument after the program name
    return 0; // exit with a success code
}
