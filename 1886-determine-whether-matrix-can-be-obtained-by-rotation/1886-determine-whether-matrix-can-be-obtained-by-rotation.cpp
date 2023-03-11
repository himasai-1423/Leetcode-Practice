class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> check(4, true);
        int n = mat.size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]!=target[i][j]) check[0] = false;
                if(mat[i][j]!=target[j][n-i-1]) check[1] = false;
                if(mat[i][j]!=target[n-i-1][n-j-1]) check[2] = false;
                if(mat[i][j]!=target[n-j-1][i]) check[3] = false;
            }
        }
        return check[0]||check[1]||check[2]||check[3];
    }
};