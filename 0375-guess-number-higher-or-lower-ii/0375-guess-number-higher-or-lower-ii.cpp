class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return calcMinMoney(1, n, dp);
    }
    
    int calcMinMoney(int l, int r,  vector<vector<int>> &dp){
        if(l>=r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int res = INT_MAX;
        
        for(int i=l; i<=r; i++) {
            int ans = i + max(calcMinMoney(l, i-1, dp), calcMinMoney(i+1, r, dp));
            res = min(res, ans);
        }
        return dp[l][r]=res;
    }
};