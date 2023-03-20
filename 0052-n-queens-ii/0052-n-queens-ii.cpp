class Solution {
public:
    int cnt = 0;
    unordered_set<int> col, posDig, negDig;
    
    void arrangeQueens(int n, int row) {
        if(row==n) {
            cnt++;
            return;
        }
        
        for(int c=0; c<n; c++) {
            if(col.count(c) || posDig.count(row+c) || negDig.count(row-c))
                continue;
            
            col.insert(c);
            posDig.insert(row+c);
            negDig.insert(row-c);
            
            arrangeQueens(n, row+1);
            
            col.erase(c);
            posDig.erase(row+c);
            negDig.erase(row-c);
        } 
    }
    
    int totalNQueens(int n) {
        arrangeQueens(n, 0);
        return cnt;
    }
};