class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n==1) return {0};
        
        vector<int> adj[n], degree(n, 0);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1)
                q.push(i);
        }
        
        while(!q.empty()) {
            int size = q.size();
            res.clear();
            for(int i=0; i<size; i++) {
                auto cur = q.front();
                q.pop();
                res.push_back(cur);
                for(auto &neighbour: adj[cur]) {
                    degree[neighbour]--;
                    if(degree[neighbour]==1) 
                        q.push(neighbour);
                }
            }
        }
        return res;
    }
};