#include<stdio.h>
#include<stdlib.h>


#pragma pack(1) // this will pack the structure members in 1 byte boundary

struct packed{
    char ch; 
    int i; 
    float f;
};

int main(){
    printf("packed %d\n" , sizeof(packed));
    return 0;
}