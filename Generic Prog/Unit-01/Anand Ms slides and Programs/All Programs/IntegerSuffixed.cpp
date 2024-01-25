#include <iostream>
using namespace std;

int main()
{
    
    //defining integer-literal
    const int INTEGER = 128; 
    //defining unsigned integer-literal
    const unsigned int UNSIGNED = 3147483647U;
    //defining long integer-literal
    const long int LONG = 2147483646L;
    //defining unsigned long integer-literal
    const unsigned int UNSIGNED_LONG = 4294967294UL;
    //defining long long integer-literal
    const long long int LONG_LONG = 5294967294LL;
    //defining unsigned long long integer-literal
    const unsigned long long int UNSIGNED_LONG_LONG = 18446744073709551610ULL;
    
    //display of result through literals
    cout<<"Integer Literal: "<<INTEGER<<"\n"; 
    cout<<"Unsigned Integer Literal: "<<UNSIGNED<<"\n";    
    cout<<"Long Integer Literal: "<<LONG<<"\n";    
    cout<<"Unsigned Long Integer Literal: "<<UNSIGNED_LONG<<"\n";
    cout<<"Long Long Int Literal: "<<LONG_LONG<<"\n";
    cout<<"Unsigned Long Long Int Literal: "<<UNSIGNED_LONG_LONG<<"\n";
}
