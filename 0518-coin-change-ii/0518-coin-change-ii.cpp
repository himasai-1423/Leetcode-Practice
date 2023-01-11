class Solution {
public:
    int coinWays(int amount, vector<int>& coins, int idx, vector<vector<int>> &dp){
        if(amount==0) return 1;
        
        else if(amount<0 || idx>=coins.size())
            return 0;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int ways = 0;
        if(amount-coins[idx]<0)
            ways = coinWays(amount, coins, idx+1, dp);
        
        else{
            int takeCoin = coinWays(amount-coins[idx], coins, idx, dp);
            int leaveCoin = coinWays(amount, coins, idx+1, dp);
            
            ways = takeCoin + leaveCoin;
        }
        
        return dp[idx][amount] = ways;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+4, -1));
        int ways = coinWays(amount, coins, 0, dp);
        
        return ways;
    }
};