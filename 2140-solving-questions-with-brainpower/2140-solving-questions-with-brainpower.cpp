class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        int n = questions.size();
        dp[n-1] = questions[n-1][0];
        for(int i = n-2; i>=0; i--) {
            dp[i] = questions[i][0];
            int skip = questions[i][1];
            
            if(i+skip+1<n)
                dp[i] += dp[i+skip+1];
            
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};