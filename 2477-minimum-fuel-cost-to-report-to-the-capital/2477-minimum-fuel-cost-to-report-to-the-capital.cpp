class Solution {
public:
    long long fuel = 0;
    
    long long dfs(int node, int par, vector<int> adj[], int seats) {
        int passengers = 1;
        for(auto &child: adj[node]) 
            if(child != par) 
                passengers += dfs(child, node, adj, seats);

        if (node != 0) 
            fuel += ceil((double)passengers / seats);
        
        return passengers ;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n+1];
        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, adj, seats);
        
        return fuel;
    }
};