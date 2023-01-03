class Solution {
public:
    int dp[101][101];
    int uniquePathTraversal(vector<vector<int>>& obstacleGrid, int i, int j, int m , int n){
        if(i>m || j>n) return 0;
        
        if(obstacleGrid[i][j] == 1) return 0;
        
        if(i==m && j==n) return 1;
               
        if(dp[i][j] != -1) return dp[i][j];
        
        int total = uniquePathTraversal(obstacleGrid, i+1, j, m, n) + uniquePathTraversal(obstacleGrid, i, j+1, m, n);
        
        return dp[i][j] = total;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return uniquePathTraversal(obstacleGrid, 0, 0, m-1, n-1);
    }
};