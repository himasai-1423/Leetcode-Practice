#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    const int MOD = 1e9+7;
    int dijkstra(vector<pll> adj[], int n) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pll, vector<pll>, greater<pll>> q;
        q.push({0, 0}); //{dist, node}
        while(!q.empty()) {
            auto [parDist, parNode] = q.top();
            q.pop();
            
            if(parDist>dist[parNode]) continue;
            
            for(auto &[childNode, childDist]: adj[parNode]) {
                if(childDist + parDist < dist[childNode]) {
                    dist[childNode] = childDist + parDist;
                    ways[childNode] = ways[parNode];
                    q.push({dist[childNode], childNode});
                }
                else if(childDist + parDist == dist[childNode])
                    ways[childNode] = (ways[parNode]+ways[childNode])%MOD;
            }
        }
        
        return ways[n-1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll> adj[n];
        
        for(auto &road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        return dijkstra(adj, n);
    }
};