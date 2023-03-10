class Solution {
public:    
    int change(vector<int> &coins,int idx, int amt, vector<vector<int>> &dp){
        if(amt == 0) return 0;
        else if(idx<0 || amt<0) return INT_MAX-1;
        
        if(dp[idx][amt]!= -1) return dp[idx][amt];
                
        int res = -1;
        
        int takeCoin = 1 + change(coins, idx, amt - coins[idx], dp);
        int doNotTakeCoin = 0 + change(coins, idx - 1, amt - 0, dp);
            
        res = min(takeCoin, doNotTakeCoin);
        
        return dp[idx][amt] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int res = change(coins, coins.size()-1, amount, dp);
        
        return res==INT_MAX-1?-1:res;
    }
};