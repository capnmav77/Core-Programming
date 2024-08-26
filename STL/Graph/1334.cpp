class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> costmap(n,vector<int>(n,INT_MAX));
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto e:edges){
            adj[e[0]].push_back({e[2],e[1]});
            adj[e[1]].push_back({e[2],e[0]});
        }

        for(int i=0 ; i<n ; ++i){
            dijkstra(i , adj , costmap);
        }
        int mincount = INT_MAX , index = -1;
        for(int i=0 ;i< n ; i++){
            int count = 0;
            for(int j=0 ; j<n ; j++){
                if(i!= j && costmap[i][j]<=k){
                    count++;
                }
            }
            if(mincount>count){
                mincount = count ;
                index = i;
            }
            else if(mincount == count){
                index = max(index,i);
            }
        }
        return index;
    }

    void dijkstra(int source, const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& costmap) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (distance, node)
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        costmap[source] = dist;
    }
};
