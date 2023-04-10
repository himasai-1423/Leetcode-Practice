class Solution {
public:
    int landCnt = 0;
    
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis) {
        if(i<0 || j<0 || i>=grid.size() || j>= grid[i].size() || vis[i][j] || grid[i][j]==0) 
            return true;
        
        vis[i][j] = true;
        landCnt++;
        
        bool a, b, c, d;
        a = dfs(i, j+1, grid, vis);
        b = dfs(i+1, j, grid, vis);
        c = dfs(i-1, j, grid, vis);
        d = dfs(i, j-1, grid, vis);
        
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[i].size()-1) 
            return false;
        
        return a&&b&&c&&d;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(!vis[i][j]) {
                    landCnt = 0;
                    if(dfs(i, j, grid, vis))
                        res += landCnt;
                }
            }
        }
        return res;
    }
};