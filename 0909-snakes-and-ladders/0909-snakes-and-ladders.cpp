class Solution {
public:
    pair<int, int> intToDim(int cell, int n) {
        int r = (cell-1)/n;
        int c = (cell-1)%n;
        if(r%2)
            c = n - 1 - c;
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int  n=board.size();
        reverse(board.begin(), board.end());
        
        unordered_set<int> vis; 
        queue<pair<int, int>> q;
        q.push({1, 0}); //{cell, moves}
        
        while(!q.empty()) {
            auto cell = q.front();
            int square = cell.first;
            int moves = cell.second;
            q.pop();
            
            for(int i=1; i<=6; i++) {
                int nextCell = i + square;              
                auto dim = intToDim(nextCell, n);
                int x = dim.first;
                int y = dim.second;
                
                if(board[x][y]!=-1) nextCell = board[x][y];
                if(nextCell==n*n) return moves+1;
                
                if(!vis.count(nextCell)) {
                    vis.insert(nextCell);
                    q.push({nextCell, moves+1});
                }   
            }
        }
        return -1;
    }
};