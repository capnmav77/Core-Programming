#include <cassert>
#include <iostream>


// an assertion is a statement used to state or assert that the expression 
// must be true
template<class...A, class...B> void func(A...arg1,int sz1, int sz2, B...arg2)  
{
   assert( sizeof...(arg1) == sz1);
   assert( sizeof...(arg2) == sz2);
}

int main(void)
{
   //A:(int, int, int), B:(int, int, int, int, int) 
   func<int,int,int>(1,2,3,3,5,1,2,3,4,5);

   //A: empty, B:(int, int, int, int, int)
   func(0,5,1,2,3,4,5);
   return 0;
}