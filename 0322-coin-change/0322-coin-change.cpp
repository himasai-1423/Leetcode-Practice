class Solution {
public:
    int minCoins(vector<int>& coins, int amount, int idx,vector<vector<int>> &dp){
        if(amount==0) 
            return 0;
        
        if(amount<0 || idx>=coins.size())
            return INT_MAX-1;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int res = -1;
        if(amount - coins[idx]<0)
            res =  0 + minCoins(coins, amount, idx+1, dp);
        
        else{
            int takeCoin = 1 + minCoins(coins, amount - coins[idx], idx, dp);
            int leaveCoin = 0 + minCoins(coins, amount, idx+1, dp);
            
            res = min(takeCoin, leaveCoin);
        }
        return dp[idx][amount] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+3, -1));
        int res = minCoins(coins, amount, 0, dp);
        return res==INT_MAX-1?-1:res;
    }
};