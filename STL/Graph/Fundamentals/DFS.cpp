#include<iostream>
#include<bits/stdc++.h>

using namespace std; 


class DSF{
    public : 
    void depth_first_search(vector<vector<int>> adjMat, vector<int> &dfs ){
        vector<bool> visited(adjMat.size(), false);
        for(int i=0 ; i<adjMat.size(); i++){
            if(!visited[i]){
                this->dfs(adjMat, visited, dfs, i);
            }
        }
    }

    void dfs(vector<vector<int>> adjMat, vector<bool> &visited, vector<int> &dfs, int node){
        visited[node] = true;
        dfs.push_back(node);
        for(int i=0 ; i<adjMat.size(); i++){
            if(adjMat[node][i] == 1 && !visited[i]){
                this->dfs(adjMat, visited, dfs, i);
            }
        }

    }

};

int main(){
    vector<vector<int>> adjMat(5, vector<int>(5,0));
    adjMat[0][1] = 1;
    adjMat[1][0] = 1;
    adjMat[0][2] = 1;
    adjMat[2][0] = 1;
    adjMat[1][3] = 1;   
    adjMat[3][1] = 1;
    adjMat[2][4] = 1;
    adjMat[4][2] = 1;
    adjMat[3][4] = 1;
    adjMat[4][3] = 1;

    
    vector<int>dfs;
    DSF DFS;
    DFS.depth_first_search(adjMat,dfs);
    for(auto i : dfs){
        cout<<i<<" ";
    }
    return 0;
}