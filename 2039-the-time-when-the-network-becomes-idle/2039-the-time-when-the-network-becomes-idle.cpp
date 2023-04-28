class Solution {
public:
    const int INF = 1e9+10;
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> adj[n];
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> time(n, INF);
        queue<int> q;
        q.push(0);
        time[0] = 0;
        
        while(!q.empty()) {
            int par = q.front();
            q.pop();
            for(auto child: adj[par]) {
                if(time[child] == INF){
                    time[child] = time[par] + 1;
                    q.push(child);
                }
            }
        }
        
        int res = 0;
        for(int i=1; i<n; i++) {
            int extraSignals =(time[i]*2 - 1)/patience[i];
            int lastOut = extraSignals * patience[i]; 
            int lastIn = lastOut + time[i]*2; 
            
            res = max(res, lastIn);
        }
        return res+1;    
    }
};