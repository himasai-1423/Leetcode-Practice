class Solution {
public:
    int findSquares(int n, vector<int> &dp){
        if(n==0)
            return 0;
        
        if(dp[n]!= -1) return dp[n];
        
        int res = INT_MAX;
        for(int i=1; i*i<=n; i++){
            res = min(res, 1+ findSquares(n-(i*i), dp));
        }        
        return dp[n]= res; 
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        
        return findSquares(n, dp);
    }
};