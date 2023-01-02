class Solution {
public:
    int countCombinations(int amount, vector<int> &coins, int idx, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(idx<0) return 0;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int ways = 0;
        for(int coin_amt = 0; coin_amt<=amount ; coin_amt=coin_amt+coins[idx]){
            ways += countCombinations(amount-coin_amt, coins, idx-1, dp);
        }
        
        return dp[idx][amount]= ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(310, vector<int>(5010, -1));
        
        return countCombinations(amount, coins, coins.size()-1, dp);
    }
};