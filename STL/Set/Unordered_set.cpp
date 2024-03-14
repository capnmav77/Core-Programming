#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    //unordered_set<data_type> name;
    //avaerage O(1) and worst O(n)
    //it also uses hash map, the value is hashed so that the insertion is randomised
    //key is always unique

    unordered_set<string> stringSet;

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");
    stringSet.insert("fast");

    for(auto itr = stringSet.begin(); itr != stringSet.end();itr++)
    {
        cout<<(*itr)<<endl;
    }
    

    //some useful functions
    /*
    find //finds if a value exists in the structure
    clear //removes all of the elements, empties
    empty //check if empty
    reverse //reverse the container
    size //
    */
    return 0;
}