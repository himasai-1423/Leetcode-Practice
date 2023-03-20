class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> col, posDig, negDig;
    
    void backtrack(vector<string> &board, int row) {
        if(row==board.size()) {
            res.push_back(board);
            return;
        }
        
        for(int c=0; c<board.size(); c++) {
            if(col.count(c) || posDig.count(c+row) || negDig.count(row-c))
                continue;
            
            col.insert(c);
            posDig.insert(row+c);
            negDig.insert(row-c);
            board[row][c] ='Q';
            
            backtrack(board, row+1);
            col.erase(c);
            posDig.erase(row+c);
            negDig.erase(row-c);
            board[row][c] ='.';
        }     
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
};