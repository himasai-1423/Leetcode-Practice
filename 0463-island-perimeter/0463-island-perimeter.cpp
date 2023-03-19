class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0)
            return 1;

        if(vis[i][j]==true) return 0;
        
        vis[i][j] = true;
        int sum = dfs(i+1, j, grid, vis);
        sum += dfs(i-1, j, grid, vis);
        sum += dfs(i, j-1, grid, vis);
        sum += dfs(i, j+1, grid, vis);
        
        return sum;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0; i<grid.size(); i++) 
            for(int j=0; j<grid[i].size(); j++) 
                if(grid[i][j])
                    return dfs(i, j, grid, vis);
        
        return -1;
    }
};