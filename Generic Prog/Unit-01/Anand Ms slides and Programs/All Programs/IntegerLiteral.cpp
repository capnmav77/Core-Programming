#include <iostream>
using namespace std;

int main()
{
    
    //defining decimal-literal
    const int DECIMAL = 128; 
    //defining octal-literal
    const int OCTAL = 0200;
    //defining hex-literal
    const int HEX = 0x80;
    //defining binary-literal
    const int BINARY = 0b10000000;
    
    //display of result through literals
    cout<<"Decimal Literal: "<<DECIMAL<<"\n"; 
    cout<<"Octal Literal: "<<OCTAL<<"\n";    
    cout<<"Hex Literal: "<<HEX<<"\n";    
    cout<<"Binary Literal: "<<BINARY<<"\n";
}
