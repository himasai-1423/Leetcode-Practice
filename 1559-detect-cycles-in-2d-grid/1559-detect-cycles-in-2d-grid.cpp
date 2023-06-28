class Solution {
public:
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(int i, int j, int x, int y, vector<vector<bool>> &vis, vector<vector<char>>& grid) {
        vis[i][j] = true;
        
        for(auto &move: moves) {
            int a = i + move.first;
            int b = j + move.second;
            
            if(a>=0 && b>=0 && a<grid.size() && b<grid[0].size() && grid[a][b]==grid[i][j] && (x!=a || y!=b))
               if(vis[a][b] || dfs(a, b, i, j, vis, grid))
                   return true;
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(!vis[i][j] && dfs(i, j, -1, -1, vis, grid))
                    return true;
            }
        }
        return false;
    }
};