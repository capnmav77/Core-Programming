#include <stdio.h>
#include <stdarg.h>

double average(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for(int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }

    va_end(args);

    return (double)total / count;
}

int main() {
    printf("Average of 2, 3, 4, 5 = %.2f\n", average(4, 2, 3, 4, 5));
    printf("Average of 5, 10, 15 = %.2f\n", average(3, 5, 10, 15));
    return 0;
}
