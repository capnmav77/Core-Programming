#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    //declaration of map
    // map <Dtype , Dtype> variable_name;

    map<int, string> m;

    

    //intialization of map

    //key value pair
    m[1] = "abc";
    m[2] = "def";
    m[3] = "ghi";

    //or here's map insert function with make_pair
    //make_pair is used to make a pair of key and value
    m.insert(make_pair(4, "jkl"));
    m.insert(make_pair(5, "mno"));

    //or here's map insert function without make_pair with curly braces
    m.insert({5, "mno"}); 
    m.insert({6, "pqr"});
    

    //accessing the map
    //map iterator 

    map<int, string>::iterator it;

    for(it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}