class Solution {
public:
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                         {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    
    int bfs(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid.size(), false));
        
        int dist = 1;
        q.push({0, 0});
        vis[0][0] = true;
        
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                for(auto &move: moves) {
                    int x = node.first + move.first;
                    int y = node.second + move.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid.size()) {
                        if(grid[x][y]==0 && vis[x][y]==false) {
                            if(x == grid.size()-1 && y == grid.size()-1)
                                return dist+1;
                            cout<<x<<" "<<y<<" "<<dist<<endl;
                            q.push({x, y});
                            vis[x][y] = true;
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==1 && !grid[0][0]) return 1;  
        return bfs(grid);
    }
};