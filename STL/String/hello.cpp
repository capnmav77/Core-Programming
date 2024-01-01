#include<iostream>
#include<string>
#include<sstream>
using namespace::std;

int main(){
    int count = 12;
    string res;
    res.push_back('a');
    res += to_string(count);
    cout<<res;
    return 0;
}