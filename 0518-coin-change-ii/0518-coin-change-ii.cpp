class Solution {
public:
    int countCombinations(int amount, vector<int> &coins, int idx, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(idx<0) return 0;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int ways = 0;
        
        if(coins[idx] > amount)
        {
            ways = countCombinations(amount, coins, idx-1, dp);
        }
        
        else{
            ways = countCombinations(amount-coins[idx], coins, idx, dp) + 
                countCombinations(amount, coins, idx-1, dp);
        }        
        
        return dp[idx][amount]= ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(310, vector<int>(5010, -1));
        
        return countCombinations(amount, coins, coins.size()-1, dp);
    }
};