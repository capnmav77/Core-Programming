// Program to demonstrate function overloading

#include <iostream>
using namespace std;

void SumNum(int A, int B);
void SumNum(int A, int B, int C);
void SumNum(int A, int B, int C, int D);

int main()
{
    SumNum(1,2);
    SumNum(1,2,3);
    SumNum(1,2,3,4);
    
    return 0;
}

void SumNum(int A, int B)
{
     cout<< endl << "SUMNUM is : "<< A+B;     
}

void SumNum(int A, int B, int C)
{
     cout<< endl << "SUMNUM is : "<< A+B+C;  
}

void SumNum(int A, int B, int C, int D)
{
     cout<< endl << "SUMNUM is : "<< A+B+C+D;     
}
