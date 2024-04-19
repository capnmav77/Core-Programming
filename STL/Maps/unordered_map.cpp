#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{

    //declaration of unordered_map
    // unordered_map <Dtype , Dtype> variable_name;

    unordered_map<int, string> m;

    //insertion into the unordered_map
    m[1] = "abc";
    m[3] = "def";
    m[2] = "ghi";

    //or here's unordered_map insert function with make_pair
    //make_pair is used to make a pair of key and value
    
    m.insert(make_pair(5, "jkl"));
    m.insert(make_pair(4, "mno"));

    //iterator 
    for(auto it = m.begin() ; it != m.end() ; ++it){
        cout<<it->first<<"--"<<it->second<<endl;
    }

    //this uses a hash function instead of a RB tree to store the elements making fetching the elements faster 
    //but the elements are not sorted
    
    return 0;
}