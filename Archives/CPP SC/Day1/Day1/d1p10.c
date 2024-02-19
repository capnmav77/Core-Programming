#include <stdio.h>
#include <stdbool.h>

typedef enum {
    RED, // 0
    GREEN, // 1
    BLUE // 2
} color_t;
#define SET_COLOR(c, x) do { \
    if (is_valid_color(x)) { \
        (c) = (x); \
    } else { \
        printf("Invalid color\n"); \
    } \
} while (0)

bool is_valid_color(int x)
{
    return x >= RED && x <= BLUE;
}
void print_color(color_t c)
{
    switch (c)
    {
        case RED:
            printf("Red\n");
            break;
        case GREEN:
            printf("Green\n");
            break;
        case BLUE:
            printf("Blue\n");
            break;
        default:
            printf("Invalid color\n");
            break;
    }
}
int main()
{
    color_t c;
    SET_COLOR(c, 42); // Invalid color
    print_color(c); // Invalid color
    SET_COLOR(c, BLUE); // OK
    print_color(c); // Blue
    return 0;
}
