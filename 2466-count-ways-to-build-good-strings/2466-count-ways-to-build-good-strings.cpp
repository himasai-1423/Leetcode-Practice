class Solution {
public:
    int MOD = 1e9+7;
    int dfs(int low, int high, int zero, int one, int len, vector<int> &dp) {
        if(len>high) return 0;
        
        if(dp[len] != -1) return dp[len];
        
        dp[len]= len>=low?1:0;
        dp[len] += (dfs(low, high, zero, one, len+zero, dp) + 
            dfs(low, high, zero, one, len+one, dp))%MOD;
        
        return dp[len];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        
        return dfs(low, high, zero, one, 0, dp);
    }
};