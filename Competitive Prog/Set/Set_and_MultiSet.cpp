#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{

    //declaration of set 
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(5);
    s.insert(3);

    cout<<"Set: "<<endl;
    set<int>::iterator it;
    for(it = s.begin() ; it != s.end() ; ++it){
        cout<<*it<<endl;
    }

    // declaration of multiset 
    multiset<int> ms;

    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(5);
    ms.insert(3);

        cout<<"MultiSet: "<<endl;
    multiset<int>::iterator it2;
    for(it2 = ms.begin() ; it2 != ms.end() ; ++it2){
        cout<<*it2<<endl;
    }

    return 0;
}