#include <stdio.h>

void swap (int *, int *);

static int jlt = 100;

int main ()
{
	int i = 10, j = 20;
	printf ("Before swap: i is %d j is %d\n", i, j);
	swap (&i, &j);
	printf ("After swap: i is %d j is %d\n", i, j);
	return 0;
}

