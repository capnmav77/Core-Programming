#include <iostream> 

using namespace std;


int function1(){
    return 2;
}

char function2(){
    return '0';
}

int main(){
    //datatype of x is same as return type of fun

    decltype(function1()) x;
    decltype(function2()) y;

    cout<< typeid(x).name()<<endl;
    cout<< typeid(y).name()<<endl;

    return 0 ;
}