#include <stdio.h>

extern int jlt;

void swap (int *i1, int *i2)
{
	printf ("value of jlt is %d\n", jlt);
	int temp = *i1;
	*i1 = *i2;
	*i2 =temp;
}
