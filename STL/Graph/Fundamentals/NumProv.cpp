#include<iostream>
#include<bits/stdc++.h>

using namespace std; 


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int count = 0 ;
        for(int i=0 ; i<isConnected.size(); ++i){
            for(int j=0 ; j<isConnected[0].size() ; ++j){
                if(isConnected[i][j]==1 && !visited[j]){
                    dfs(isConnected , visited , j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected , vector<int> &visited , int node){
        visited[node] = 1;
        for(int i=0 ; i<isConnected.size() ; i++){
            if(isConnected[node][i]==1 && !visited[i]){
                dfs(isConnected , visited , i);
            }
        }
        return;
    }
};

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.findCircleNum(adj) << endl;
        
    return 0;
}