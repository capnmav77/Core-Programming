#include<stdio.h>
#include<stdlib.h>


#pragma pack(1)

struct packed{
    char ch; 
    int i; 
    float f;
};

int main(){
    printf("packed %d\n" , sizeof(packed));
    return 0;
}