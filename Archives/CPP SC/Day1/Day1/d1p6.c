#include <stdio.h>

int main() {
    goto skip_initialization;

    int number;
    number = 10;

skip_initialization:
    printf("Number: %d\n", number);

    return 0;
}
