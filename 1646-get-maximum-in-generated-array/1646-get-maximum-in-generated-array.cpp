class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n+2, -1);
        
        if(n==0) return 0;
        
        dp[0] =0;
        dp[1]=1;
        
        int maxi = 1;
        
        for(int i=2;i<=n; i++){
            if (i % 2) dp[i] = dp[i / 2] + dp[i / 2 + 1];
            else dp[i] = dp[i / 2];
            maxi=max(maxi, dp[i]);
        }
        return maxi;
    }
};