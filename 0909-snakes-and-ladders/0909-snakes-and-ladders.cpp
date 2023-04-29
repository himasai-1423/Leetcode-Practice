class Solution {
public:
    pair<int, int> intToPos(int square, int n) {
        int r = (square-1)/n;
        int c = (square-1)%n;
        if(r%2)
            c = n - 1 - c;
        return {r, c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        reverse(board.begin(), board.end());
        
        set<int> vis;
        queue<pair<int, int>> q;
        q.push({1, 0}); //{square, moves}
        while(!q.empty()) {
            auto node = q.front();
            int square = node.first;
            int moves = node.second;
            q.pop();
            for(int i = 1; i<7; i++) {
                int nextSquare = i + square;
                auto dim = intToPos(nextSquare, n);
                if(board[dim.first][dim.second] != -1) 
                    nextSquare = board[dim.first][dim.second];
                if(nextSquare == n*n)
                    return moves + 1;
                
                if(!vis.count(nextSquare)) {
                    vis.insert(nextSquare);
                    q.push({nextSquare, moves + 1});
                } 
            }
        }
        return -1;
    }
};