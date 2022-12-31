class Solution {
    public:
    int totalStairs(int n, vector<int> &dp){
        if(n==0) return 1;
        else if(n<0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = totalStairs(n-1, dp) + totalStairs(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        return totalStairs(n, dp);
    }
};