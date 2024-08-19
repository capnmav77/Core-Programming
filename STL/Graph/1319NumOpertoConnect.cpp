// class Solution {
// public:
//     int re = 0;
//     int makeConnected(int n, vector<vector<int>>& connections)
//     {
//         vector<vector<int>> adj(n);
//         vector<int> visited(n,0);
//         map<pair<int,int>,int> pathVisited;
//         int count = 0;
//         for(auto i:connections)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//             pathVisited[{i[0],i[1]}] = 0;
//             pathVisited[{i[1],i[0]}] = 0;
            
//         }

//         for(int i = 0;i < n;i++)
//         {
//             if(!visited[i])
//             {
//                 dfs(adj,visited,i,pathVisited);
//                 count++;
//             }
//         }
//         if(count == 1) return 0;
//         cout << count << " " << re;
//         return re >= count-1 ? count-1 : -1;  
//     }

//     void dfs(vector<vector<int>>&adj , vector<int>& visited,int node,map<pair<int,int>,int>& pathVisited)
//     {
//         visited[node] = 1;

//         for(int i:adj[node])
//         {
//             if(!visited[i])
//             {
//                 pathVisited[{node,i}] = 1;
//                 pathVisited[{i,node}] = 1;
//                 dfs(adj,visited,i,pathVisited);
//             }
//             else if (pathVisited[{node,i}] == 0 && pathVisited[{i,node}] == 0){
//                 re++;
//                 pathVisited[{node,i}] = 1;
//                 pathVisited[{i,node}] = 1;
//             };
//         }
//     }
// };

class DSU{
    public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0;
        int extra=0;
        DSU d(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(d.findParent(u)==d.findParent(v)){
                extra++;
            }
            else d.unionBySize(u,v);
        }
        for(int i=0;i<n;i++){
            if(d.parent[i]==i) ans++;
        }
        if(extra>=ans-1) return ans-1;
        return -1;
    }
};
