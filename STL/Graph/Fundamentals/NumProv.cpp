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



class Solution {
public:
    int m,n;
    class DisjointSet
    {
        public:
        vector<int> parent,size;

        DisjointSet(int capacity)
        {
            parent.resize(capacity);
            size.resize(capacity,1);
            for(int i = 0;i < capacity;i++)
            {
                parent[i] = i;
            }
        }

        int findUParent(int node)
        {
            if(parent[node] == node)return node;
            return parent[node] = findUParent(parent[node]);
        }

        void UnionBySize(int u,int v)
        {
            int pu = findUParent(u);
            int pv = findUParent(v);
            if(pu == pv) return;

            if(size[pu] >= size[pv])
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else
            {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        m = isConnected.size();
        vector<int> visited(m,0);
        int count  = 0;
        vector<vector<int>> edges;

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(i != j && isConnected[i][j])
                {
                    edges.push_back({i,j});
                    edges.push_back({j,i});
                }
            }
        }
        DisjointSet s(m);
        for(auto i:edges)
        {
            int u = i[0];
            int v = i[1];
            if(s.findUParent(u) != s.findUParent(v))
            {
                s.UnionBySize(u,v);
            }
        }

        for(int i = 0;i < m;i++)
        {
            if(s.parent[i] == i) count++;
        }

        return count;
    }

    void bfs(vector<int>& visited,vector<vector<int>>& adj,int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty())
        {
            int parentNode = q.front();
            q.pop();
            for(int adjNode:adj[parentNode])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1 ;
                    q.push(adjNode);
                }
            }
        }
    }
};
