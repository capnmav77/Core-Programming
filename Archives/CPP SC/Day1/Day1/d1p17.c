#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p;
    p.x = 10;
    p.y = 20;

    printf("Point is at (%d, %d)\n", p.x, p.y);
    printf("Size of Point is: %lu bytes\n", sizeof(Point));

    Point *ptr = &p;  // pointer to p

    printf("Point via pointer is at (%d, %d)\n", ptr->x, ptr->y);

    // Demonstrate that (*ptr).x and ptr->x are equivalent
    if((*ptr).x == ptr->x) {
        printf("(*ptr).x and ptr->x are equivalent\n");
    } else {
        printf("(*ptr).x and ptr->x are not equivalent\n");
    }

    return 0;
}
