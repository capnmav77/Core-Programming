#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//let's write a templatized function to print the set
template<typename T>
void printSet(const set<T>& s) {
    
    cout << "Set: " << endl;

    typename set<T>::iterator it;

    for(it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }

}

//let's write a templatized function to print the multiset
template<typename T>
void printMultiset(const multiset<T>& ms) {

    cout << "MultiSet: " << endl;

    typename multiset<T>::iterator it;

    for(it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << endl;
    }

}

int main() {

    // declaration of set 
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(5);
    s.insert(3);

    //print the set
    printSet(s);

    // declaration of multiset 
    multiset<int> ms;

    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(5);
    ms.insert(3);

    //print the multiset
    printMultiset(ms);

    return 0;
}