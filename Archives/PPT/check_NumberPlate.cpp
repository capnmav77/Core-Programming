#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Numberplate{

    public:
    bool isValid(const string &str){
        int len = str.length();
        if(len < 9)
            return false;
        cout<<"len passed";
        for(int i=4; i<str.length(); i++){
            if(str[i] < 'A' || str[i] > 'Z')
                return false;
        }
        //check for first 2 characters to be alphabets
        if((str[0] < 'A' || str[0] > 'Z') || (str[1] < 'A' || str[1] > 'Z'))
            return false;
        cout<<"first 2 passed";

        //check for next 2 characters to be integers
        if((str[2] < '0' || str[2] > '9') || (str[3] < '0' || str[3] > '9'))
            return false;
        cout<<"next 2 passed";
        
        //check the next one or more characters are alphabets
        int i = 4;
        while(i<len && str[i] >= 'A' && str[i] <= 'Z')
            i++;
        if(i == 4)
            return false;
        cout<<"alphabets passed";
        
        //check the last 4 characters are integers
        if(i+4 != len)
            return false;
        cout<<"initial passed";
        while(i<len){
            if(str[i] < '0' || str[i] > '9')
                return false;
            i++;
        }
        return true;
    }

};


int main(){
    Numberplate np;
    np.isValid("MH12DEFG14326") ? cout<<"Valid" : cout<<"Invalid";
    return 0;
}