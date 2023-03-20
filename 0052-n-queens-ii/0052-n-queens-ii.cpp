class Solution {
public:
    int cnt = 0;
    unordered_set<int> col, posDig, negDig;
    
    void arrangeQueens(vector<string> &board, int row) {
        if(row==board.size()) {
            cnt++;
            return;
        }
        
        for(int c=0; c<board.size(); c++) {
            if(col.count(c) || posDig.count(row+c) || negDig.count(row-c))
                continue;
            
            col.insert(c);
            posDig.insert(row+c);
            negDig.insert(row-c);
            
            arrangeQueens(board, row+1);
            
            col.erase(c);
            posDig.erase(row+c);
            negDig.erase(row-c);
        } 
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        arrangeQueens(board, 0);
        return cnt;
    }
};