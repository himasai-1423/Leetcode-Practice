class Solution {
public:
    int bfs(int n, vector<pair<int, int>> adj[]) {
        queue<int> q;
        int res = 0;
        vector<bool> vis(n, false);
        
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int parNode = q.front();
            q.pop();
            
            for(auto &child: adj[parNode]) {
                int childNode = child.first;
                int wt = child.second;
                
                if(!vis[childNode]) {
                    res += wt;
                    vis[childNode] = true;
                    q.push(childNode);
                }
            }
        }
        
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        
        return bfs(n, adj);
    }
};