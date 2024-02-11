// auto declaration added in cpp 11 is a feature that automatically assigns the type of a variable based on the value assigned to it 

#include<iostream>

using namespace std;

int main(){
    auto i={1,2,3,4};
    auto k=0.3;
    auto c = "h";
    auto g = "hello";

    cout<<typeid(i).name()<<endl;
    cout<<typeid(k).name()<<endl;
    cout<<typeid(c).name()<<endl;
    cout<<typeid(g).name()<<endl;

    //cout<<type(i)<<endl;

    return 0;
}