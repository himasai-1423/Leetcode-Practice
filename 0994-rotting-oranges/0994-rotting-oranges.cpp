class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), freshCnt=0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) 
                    freshCnt++;
                if(grid[i][j]==2)
                    q.push({i, j});
            }
        }
        
        int time = 0;
        vector<pair<int, int>> dir={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!q.empty() && freshCnt>0) {
            int a = q.size();
            for(int i=0; i<a; i++) {
                auto loc = q.front();
                q.pop();
                
                for(int j=0; j<4; j++) {
                    int row = loc.first + dir[j].first;
                    int col = loc.second + dir[j].second;
                    if(row<0 || col<0 || row>=n || col>=m || grid[row][col]!=1) continue;
                    grid[row][col] = 2;
                    q.push({row, col});
                    freshCnt--;
                }
            }
            time++;
        }
        if(freshCnt!=0) return -1;
        return time;
    }
};