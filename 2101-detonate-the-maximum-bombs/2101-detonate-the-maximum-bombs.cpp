class Solution {
public:
    int dfs(int i, vector<int> adj[], vector<bool> &vis) {
        vis[i] = true;
        int cnt = 1;
        for(int &child: adj[i]) 
            if(!vis[child])
                cnt +=dfs(child, adj, vis);
        return cnt;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            long long int x0, y0, r0;
            x0 = bombs[i][0];
            y0 = bombs[i][1];
            r0 = bombs[i][2];

            for(int j=0; j<n; j++){
                if(i != j){
                    long long int x, y;
                    x = x0 - bombs[j][0];
                    y = y0 - bombs[j][1];

                    if(x*x + y*y <= r0*r0){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int res = INT_MIN;
        for(int i=0; i<n; i++) {
            vector<bool> vis(n);
            int cnt = dfs(i, adj, vis);
            res = max(res, cnt);
        }
        return res;
    }
};