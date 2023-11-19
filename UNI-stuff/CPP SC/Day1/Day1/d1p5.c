#include <stdio.h>

int main() {
    int number = 0x123;  // some number
    int mask = 0xF;  // mask for lower 4 bits

    printf("Original number: 0x%x\n", number);

    // Extract lower 4 bits
    int lower4bits = number & mask;
    printf("Lower 4 bits: 0x%x\n", lower4bits);

    // Set 2nd bit from right
    number |= 0x2;
    printf("Number after setting 2nd bit from right: 0x%x\n", number);

    return 0;
}
