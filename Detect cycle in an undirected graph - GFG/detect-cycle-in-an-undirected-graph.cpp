//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int V, vector<int> adj[], vector<bool> &vis, int par) {
        bool loopFound = false;
        vis[V] = true;
        for(int edge: adj[V]) {
            if(vis[edge] && edge==par) continue;
            if(vis[edge]) return true;
            
            loopFound |= dfs(edge, adj, vis, V);
        }
        return loopFound;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V+1);
        
        for(int i=0; i<V; i++) {
            if(vis[i]) continue;
            if(dfs(i, adj, vis, -1)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends