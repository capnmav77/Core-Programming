#include<iostream> 
#include<bits/stdc++.h>

using namespace std; 


int main() {
    // types of graphs : 
    // 1. Directed Graphs
    // 2. Undirected Graphs 
    // 3. Weighted Graphs 

    vector<vector<int>> adjList(5); // 5 vertices

    // for undirected graph: 
    vector<pair<int,int>> connections = {{0,1}, {1,2}, {2,3}, {3,4}, {4,0}, {0,2}, {1,3}, {2,4}};


    for(auto edge : connections) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }

    // perform BFS on the graph:

    queue<int> q;
    vector<bool> visited(5, false);

    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = true;
        cout << node << " ";
        for(auto neighbour : adjList[node]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
            }
        }
    }
    
    return 0;
}

