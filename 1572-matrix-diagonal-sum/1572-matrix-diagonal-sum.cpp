class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), res = 0;
        
        for(int i=0; i<n; i++) {
            res += mat[i][i];
            int j = n - i -1;
            if(i!=j)
                res += mat[i][j];
        }              
        return res;
    }
};