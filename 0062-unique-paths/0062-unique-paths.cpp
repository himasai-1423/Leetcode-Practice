class Solution {
public:
    int dp[101][101];
    int uniquePathTraversal(int i, int j, int m , int n){
        if(i==m && j==n) return 1;
        
        if(i>m || j>n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int total = uniquePathTraversal(i+1, j, m, n) + uniquePathTraversal(i, j+1, m, n);
        
        return dp[i][j] = total;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return uniquePathTraversal(0, 0, m-1, n-1);
    }
};