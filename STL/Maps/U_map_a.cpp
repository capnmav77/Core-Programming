#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    //unordered_map<type_1,type_2> name;
    //type_1 = key
    //type_2 = value
    //both could be of any type
    // implemented using hash table
    // key - >hashed ->index ->retrive value
    //average cost of search insert and deleet is O(1)
    //main the keys not stored in sorted order
    //worst case it is O(n) 



    unordered_map<string, int> umap; 

    umap["ten"] = 10; 
    umap["ten*2"] = 20; 
    umap["ten*3"] = 30; 

    for (auto x : umap) {
    cout << x.first << " " <<  x.second << endl; 
    }
    string key = "ten";
    if (umap.find(key) != umap.end()) 
        cout << key << " found\n\n"; 

    //set of functions
    /*

    count //for key number of value it has
    find //returns the iterator
    empty //checks if its empty
    bucket_size
    bucket_count
    
    */


    return 0;
}