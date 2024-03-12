#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{

    // declaration of multimap 
    // multimap <Dtype , Dtype> variable_name;

    multimap<int, string> m;

    // insertion into the multimap
    m.insert({1, "abc"});
    m.insert({2, "def"});
    m.insert({2, "ghi"});

    // accessing the multimap
    // multimap iterator
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    //basically multimap allows the same key to be inserted multiple times but with different values 


    return 0;
}