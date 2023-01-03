class Solution {
public:
    int minSum(vector<vector<int>>& grid, int m, int n, vector<vector<int>> &dp){
        if(m<0 || n<0) return INT_MAX;
        if(m==0 && n==0) return grid[0][0];
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int ans = min(minSum(grid, m-1, n, dp), minSum(grid, m, n-1, dp));
        return dp[m][n] = grid[m][n] + ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+10, vector<int>(n+10, -1));
        
        return minSum(grid, m-1, n-1, dp);
    }
};