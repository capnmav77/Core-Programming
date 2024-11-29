#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){
    string str = "Hello! How're You?";
    queue<char> q;

    for(int i=0 ; i<str.size() ; i++){
        //check for char
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){   
            q.push(str[i]);
        }   
        else if(str[i]==' '){
            if(!q.empty()){
                int tem = i-1;
                while(!q.empty() && tem>=0){
                    str[tem]=q.front();
                    q.pop();
                    tem--;
                }
            }
            continue;
        }
        else{
            int tem = i-1;
            while(!q.empty() && tem>=0){
                str[tem]=q.front();
                q.pop();
                tem--;
            }
        }
    }
    cout<<str;
    return 0;
}