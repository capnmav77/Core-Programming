#include <iostream>
using namespace std;

void printarray(int arg[], int length)
{
    for(int n=0; n<length; n++)
    {
        printf("%d ",arg[n]);
    }
    printf("\n");
}

template<class...A> void func(A...args)
{
    const int size = sizeof...(args) +5;
    printf("size %d\n", size);
    int res[sizeof...(args)+5]={99,98,args...,97,96,95};
    printarray(res,size);
}

int main(void)
{
    func();
    func(1);
    func(1,2);
    func(1,2,3);
    func(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20);
    return 0;
}