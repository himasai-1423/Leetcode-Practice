class Solution {
public:
    int maxArea = 0;
        
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]==0) 
            return 0;
        
        int res = 1;
        vis[i][j] = true;
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto &move: moves) {
            int x = move.first + i;
            int y = move.second + j;
            res += dfs(x, y, grid, vis) ;
        }
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if(!vis[i][j] && grid[i][j]==1)
                    maxArea = max(maxArea ,dfs(i, j, grid, vis));
        
        return maxArea;
    }
};