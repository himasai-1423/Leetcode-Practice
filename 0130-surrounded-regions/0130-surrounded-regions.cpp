class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        
        if(i<0 || j<0 ||i>=m || j>=n || board[i][j]!='O') return;
        board[i][j]='!';
        
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto &move: moves) {
            int x = i + move.first;
            int y = j + move.second;
            dfs(board, x, y); 
        }
    } 
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[board.size()-1][i]=='O')
                dfs(board,board.size()-1,i);
        }
        
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O')
                dfs(board,i,board[0].size()-1);
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='!')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }

    }
};