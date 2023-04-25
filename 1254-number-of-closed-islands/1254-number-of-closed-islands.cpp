class Solution {
public:
    int dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        
        if(vis[i][j] || grid[i][j]) return true;
        
        bool isClosed = true;
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vis[i][j] = true;
        for(auto &move: moves) {
            int new_i = i + move.first;
            int new_j = j + move.second;
            
            if(!dfs(new_i, new_j, vis, grid))
                isClosed = false;
        }
        return isClosed;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int n = grid.size();
        int m = grid[0].size(), res=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0 && !vis[i][j] && dfs(i, j, vis, grid))
                    res++;
            }
        }
        return res;
    }
};