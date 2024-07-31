#include<iostream> 
#include<bits/stdc++.h>

using namespace std;

class GraphAlgo{
    public : 
    void breadth_first_search(vector<int> adjList[] , vector<int> &bfs){
        vector<int> vis(5,0);
        vis[0]=1;
        queue<int> q; 
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            bfs.push_back(node);
            q.pop();
            for(auto it : adjList[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }  
};


int main(){
    vector<int> adjList[5];
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[2].push_back(4); 
    adjList[3].push_back(1);
    adjList[3].push_back(4);
    adjList[4].push_back(2);
    adjList[4].push_back(3);

    vector<int> bfs;
    GraphAlgo GraphAlgo;
    GraphAlgo.breadth_first_search(adjList,bfs);
    for(int it:bfs){
        cout<<it<<" ";
    }
    return 0;

}