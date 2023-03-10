class Solution {
public:    
    int countCoins(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp) {
        if(amount == 0) 
            return 0;
        
        if(amount<0 || idx<0) return INT_MAX-1;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int ans=-1;
        
        int takeCoin = countCoins(coins, idx, amount-coins[idx], dp)+1;
        int leaveCoin = countCoins(coins, idx-1, amount, dp);
            
        ans = min(takeCoin, leaveCoin);
        
                
        return dp[idx][amount]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int res = countCoins(coins, coins.size()-1, amount, dp);
        
        return res==INT_MAX-1?-1:res;
    }
};