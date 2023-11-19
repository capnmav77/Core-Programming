#include <bits/stdc++.h>
using namespace std;

vector <int> func(){ // declaring a function of type vector <int>
     
    vector <int> send; // declaring the vector to be returned to the main function

    return send; // returning the vector send to the main funciton
}

void display(vector<int>& num){
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<endl;
    }
}

int main(){
    
    vector <int> recieve; // declaring a vector in which we will recieve the vector returned by the function

    recieve = func(); // storing the returned vector in recieve

    // displaying the recieved vector
    cout<<endl<<"Vector recieved in the main function-->"<<endl;
    for(int i=0;i<recieve.size();i++)
     cout<<recieve[i]<<" ";
    return 0;
}