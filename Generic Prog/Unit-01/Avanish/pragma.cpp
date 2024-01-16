#include<stdlib.h>
#include<stdio.h>


// #pragma pack(4)

struct packed{
    char ch;
    int i;
    float f;
};


int main()
{
printf("packed %d\n",sizeof(packed));
return 0;

}