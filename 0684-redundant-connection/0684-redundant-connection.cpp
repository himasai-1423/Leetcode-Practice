class Solution {
public:
    vector<int> res;
    bool dfs(int node, int par, vector<int> adj[], vector<int> &vis) {
        vis[node] = true;
        for(auto &child: adj[node]) {                 
            if(!vis[child] ) {
                if (dfs(child, node, adj, vis))
                    return true;
            }
            
            else if(child != par)
                return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        vector<int> adj[n+1], vis(n+1);
        
        for(auto &edge: edges) {
            fill(begin(vis), end(vis), false);
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
            if(dfs(edge[0], 0, adj, vis)) 
                return edge;
        }
        
        return {};
    }
};