#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void sayIt(){

}


template<typename T, typename... Args>
void sayIt(T first , Args... args){
    cout<<first<<endl;
    if(sizeof...(args)){
        cout<<"sizeof...args"<<sizeof...(args)<<endl;
    }
    cout<<endl;
    sayIt(args...);
}



int main()
{
    sayIt(1,2,3,4,5,6,7,8,9);

    return 0;
}