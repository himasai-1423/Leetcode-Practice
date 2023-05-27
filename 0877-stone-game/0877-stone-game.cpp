class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &dp, vector<int> &piles) {
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = (j-i)%2==0?piles[i]:0;
        int right = (j-1)%2==0?piles[j]:0;
        
        dp[i][j] = max(dfs(i+1, j, dp, piles) + left, dfs(i, j-1, dp, piles) + right);
        return dp[i][j];
    }
    
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        return dfs(0, piles.size()-1, dp, piles)
            >=accumulate(piles.begin(), piles.end(), 0)/2;
    }
};