class Solution {
public:
    int dp[12 + 1][10000 + 1];
    int change(vector<int> &coins,int idx, int amt){
        if(amt == 0) return 0;
        else if(idx<0 || amt<0) return INT_MAX-1;
        
        if(dp[idx][amt]!= -1) return dp[idx][amt];
                
        int res = -1;
        if(amt-coins[idx]<0){
            int doNotTakeCoin = 0 + change(coins, idx-1, amt - 0);
            res = doNotTakeCoin;
        }
        
        else{
            int takeCoin = 1 + change(coins, idx, amt - coins[idx]);
            int doNotTakeCoin = 0 + change(coins, idx - 1, amt - 0);
            
            res = min(takeCoin, doNotTakeCoin);
        }
        
        return dp[idx][amt] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = change(coins,n-1 , amount);
        
        return (ans==INT_MAX-1)?-1:ans;
    }
};