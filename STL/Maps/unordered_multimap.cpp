#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    //declaration of unordered_multimap
    // unordered_multimap <Dtype , Dtype> variable_name;

    unordered_multimap<int, string> m;


    //insertion into the unordered_multimap

    m.insert({1, "abc"});
    m.insert({2, "def"});
    m.insert({2, "ghi"});
    m.insert({3, "jkl"});
    m.insert({3, "mno"});

    unordered_multimap<int, string>::iterator it;

    //iterator
    for(it = m.begin() ; it!= m .end() ; ++it){
        cout<<it->first<<"--"<<it->second<<endl;
    }

    return 0;
}