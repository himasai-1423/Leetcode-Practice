class Solution {
public:
    long long dfs(int idx, vector<vector<int>>& questions, vector<long long>& dp) {
        if(idx>=questions.size())
            return 0;
        
        if(dp[idx]!=0)
            return dp[idx];
        
        long long points = questions[idx][0];
        int skip = questions[idx][1];
        
        dp[idx] = max((points + dfs(idx+skip+1, questions, dp)), dfs(idx+1, questions, dp));
        return dp[idx];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        
        return dfs(0, questions, dp);
    }
};