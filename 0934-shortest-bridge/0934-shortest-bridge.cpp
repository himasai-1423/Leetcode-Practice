class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]!=1)
            return;
        
        grid[i][j] = 2;
        q.push({i, j});
        for(auto &dir: directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            dfs(x, y, grid);
        }
    }
    
    int bfs(vector<vector<int>>& grid) {
        int dist = 0, minDist = INT_MAX;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                
                for(auto &dir: directions) {
                    int x = dir.first + node.first;
                    int y = dir.second + node.second;
                    
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[x].size()) {
                        if(grid[x][y]==1) 
                            minDist = min(dist, minDist);
                        
                        else if(grid[x][y]==0){
                            q.push({x, y});
                            grid[x][y] = -1;
                        }
                    }
                }
            }
            dist++;
        }
        return minDist;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool flag = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    dfs(i, j, grid);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return bfs(grid);
    }
};