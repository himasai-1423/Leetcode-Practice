class Solution {
public:
    void dfs(int i, int &cnt, vector<int> adj[], vector<bool> &vis) {
        vis[i] = true;
        cnt++;
        for(int &child: adj[i]) 
            if(!vis[child])
                dfs(child, cnt, adj, vis);
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        
//         for(int i=0; i<n; i++) {
//             long long x1=bombs[i][0] , y1=bombs[i][1], r1=bombs[i][2];
//             for(int j=i+1; j<n; j++) {
//                 long long x2 = bombs[j][0] , y2=bombs[j][1], r2=bombs[j][2];
//                 long long x = (x1-x2)*(x1-x2);
//                 long long y = (y1-y2)*(y1-y2);
//                 long long d = sqrt(x+y);
                
//                 if(d<=r1)
//                     adj[i].push_back(j);
//                 if(d<=r2)
//                     adj[j].push_back(i);
//             }
//         }
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
            int cnt = 0;
            dfs(i, cnt, adj, vis);
            res = max(res, cnt);
        }
        return res;
    }
};