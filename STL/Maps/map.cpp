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
    m[3] = "def";
    m[2] = "ghi";

    //or here's map insert function with make_pair
    //make_pair is used to make a pair of key and value
    m.insert(make_pair(4, "jkl"));
    m.insert(make_pair(5, "mno"));

    //or here's map insert function without make_pair with curly braces
    m.insert({5, "mnop"}); 
    m.insert({6, "pqr"});

    m.insert({1, "stu"});
    

    //accessing the map
    //map iterator 

    map<int, string>::iterator it;

    for(it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    //if you want to pop a element from the map
    m.erase(1); // where 1 is the key value

    cout<<"after deleting 1"<<endl;

    for(it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    //if you want to pop a element from the map using the iterator


    return 0;
}