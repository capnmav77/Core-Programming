#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Bank;

template <typename T>
void printSecret(Bank<T>);


template <typename B> 
class Bank2{
    B balance;
    B secret;

    friend void printSecret(Bank<B>);
};


template<typename T> 
class Bank{
    template<typename U> 
    friend void printSecret(Bank<U>);
    template<typename U> 
    friend void setbalance(Bank<U>, U);
    T balance;
    T secret = "Secret from Bank";
    friend class Bank2<T>; // Add this line to make Bank2 a friend class
};


template<typename U> 
void printSecret(Bank<U> b){
    cout<<b.secret<<endl;
}

template <typename V>
void setbalance(Bank<V> b, V bal){
    b.balance = bal;
    cout<<b.balance<<endl;
}

int main(){
    Bank<string> b; 
    string s = "hello";
    printSecret(b);
    setbalance(b, s);
    

    return 0;
}
