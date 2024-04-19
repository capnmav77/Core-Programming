#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<typename... Ts , typename... Us>
constexpr auto multipacks(Ts... ts, Us... us){
    static_assert(sizeof...(ts) == sizeof...(us));
    cout<<"packs are equal"<<endl;
    return make_tuple(ts*us...);
}



int main()
{
    //possible packs that give error 
    //multipacks(1,2,3,4,5,6,7,8,9); // error
    //multipacks<int,int,int> (1,2,3,4,5,6); //not an error because we are specifying the type of the pack
    //the ebove splits 
    //1*2, 3*4, 5*6
    multipacks<int,int,int> (1,2,3,4,5,6,7); //error
    
    return 0;
}