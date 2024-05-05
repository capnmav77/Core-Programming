#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public : 
    int openLock(vector<string> deadends , string target){

        int oper = 0;
        unordered_set<string> vis , ends;

        for(auto deadend: deadends) ends.insert(deadend);

        if(ends.count("0000")!=0) return -1;

        vis.insert("0000");
        queue<string>  q;
        q.push("0000");

        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                string curr_state = q.front();
                q.pop();
                if(curr_state == target) return oper;

                for(int i=0 ; i<4 ; i++){
                    string new_state = curr_state;
                    new_state[i] == '9'? new_state[i]='0': new_state[i]++;
                    if(vis.count(new_state)==0 && ends.count(new_state)==0){
                        q.push(new_state);
                        vis.insert(new_state);
                    }

                    new_state = curr_state;
                    new_state[i] == '0'? new_state[i]='9': new_state[i]--;
                    if(vis.count(new_state)==0 && ends.count(new_state)==0){
                        q.push(new_state);
                        vis.insert(new_state);
                    }
                }
            }
            oper++;
        }
        return -1;
    }

};


int main()
{

    vector<string> deadends ={"0201","0101","0102","1212","2002"};
    string target = "0202";
    Solution s;


    cout<<s.openLock(deadends,target)<<endl;

    return 0;
}