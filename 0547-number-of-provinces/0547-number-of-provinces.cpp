class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>>& isConnected) {
        vis[node] = true;
        
        for(int i=0; i<isConnected.size(); i++) 
            if(isConnected[node][i] && !vis[i])
                dfs(i, vis, isConnected);
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(isConnected.size(), false);
        int cnt=0;
        for(int i=0; i<isConnected.size(); i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};