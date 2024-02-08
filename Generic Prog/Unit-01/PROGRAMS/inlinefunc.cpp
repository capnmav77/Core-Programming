// instead of depending on the function call to be made and the function get's called 
// we use inline function where the compiler replaces the function declaration with the function content 
// compiler won't always guarentee to treat it as a inline 

#include<iostream>

using namespace std;

inline void disp(int n){
    cout<<n<<endl;
}


int main(){
    int i=5; 
    disp(i);
    return 0;
}