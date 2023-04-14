class Solution {
public:
    int lPSubseq(int l, int r, string &s, vector<vector<int>> &dp) {
        if(l==r) return 1;
        if(l>r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        if(s[l]==s[r])
            return dp[l][r] = 2 + lPSubseq(l+1, r-1, s, dp);
        
        return dp[l][r] = max(lPSubseq(l+1, r, s, dp), lPSubseq(l, r-1, s, dp));
     }
    
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return lPSubseq(0, s.size()-1, s, dp);
    }
};