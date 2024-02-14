#include <stdio.h>

// function declaration
void amma(void); // a function that prints "amma"
void appa(void); // a function that prints "appa"

// function definition
void amma(void)
{
    printf("amma\n"); // print "amma"
}

void appa(void)
{
    printf("appa\n"); // print "appa"
}

int main(void)
{
    // function call
    amma(); // call the amma function
    appa(); // call the appa function

    // pointer to a function
    void (*func_ptr)(void); // declare a pointer to a function that takes no arguments and returns void

    // associate the pointer to the functions
    func_ptr = amma; // assign the address of the amma function to the pointer
    func_ptr(); // call the function pointed by the pointer

    func_ptr = appa; // assign the address of the appa function to the pointer
    func_ptr(); // call the function pointed by the pointer

    return 0;
}
