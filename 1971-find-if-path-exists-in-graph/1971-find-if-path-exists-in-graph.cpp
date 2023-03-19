class Solution {
public:
    bool dfs(int curr, int destination, vector<int> adj[], vector<bool> &vis) {
        if(curr == destination)
            return true;
        bool res = false;
        
        vis[curr] = true;
        for(auto child: adj[curr]) {
            if(vis[child]) continue;
            res |= dfs(child, destination, adj, vis);
        }
        return res;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(source, destination, adj, vis);
    }
};