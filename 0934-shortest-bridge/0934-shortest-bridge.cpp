class Solution {
public:
    queue<pair<int, int>> q;
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]!=1 )
            return;
        
        grid[i][j] = 2;
        q.push({i, j});
        for(auto &move: moves) {
            int x = move.first + i;
            int y = move.second + j;
            dfs(x, y, grid);
        }
    }
    
    int bfs(vector<vector<int>>& grid) {
        int dist = 0;
        int minDist = INT_MAX;
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                
                for(auto &move: moves) {
                    int x = move.first + node.first;
                    int y = move.second + node.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()) {
                        if(grid[x][y]==1){
                            minDist = min(minDist, dist);
                        }
                        else if(grid[x][y]==0){
                            q.push({x, y});
                            grid[x][y]=-1;
                        }
                    }
                }
            }
            dist++;
        }
        return minDist;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false;
        for(int i=0;i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]==1) {
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