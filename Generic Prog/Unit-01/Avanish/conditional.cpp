#include<stdlib.h>
#include<stdio.h>

// gcc confitional -D HELLO
// gcc confitional -D HELLO=10
int main()
{
#ifdef HELLO
printf("Hello");
printf("%d",HELLO);
#endif

return 0;

}