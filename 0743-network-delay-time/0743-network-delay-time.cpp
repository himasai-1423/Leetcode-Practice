class Solution {
public:
    int INF = 1e9+10;
    int dijkstra(vector<pair<int, int>> adj[], int n, int source) {
        vector<bool> vis(n+1, false);
        vector<int> dist(n+1, INF);
        
        set<pair<int, int>> s;
        
        s.insert({0, source});
        dist[source] = 0;
        
        while(!s.empty()) {
            auto node = *s.begin();
            int par = node.second;
            int par_dist = node.first;
            s.erase(s.begin());
            if(vis[par]) continue;
            vis[par] = true;
            
            for(auto child: adj[par]) {
                int child_v = child.first;
                int wt = child.second;
                if(dist[par] + wt < dist[child_v]) {
                    dist[child_v] = wt + dist[par];
                    s.insert({dist[child_v], child_v});
                }
            }           
        }
        
        int res = 0;
        for(int i = 1; i<=n; i++) {
            if(dist[i]==INF) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto &time: times) 
            adj[time[0]].push_back({time[1], time[2]});
        
        return dijkstra(adj, n, k);
    }
};