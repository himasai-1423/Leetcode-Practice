class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size()+2, vector<int>(cuts.size()+2, -1));
        
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        
        return cut(0, cuts.size()-1, cuts, dp);
    }
    
    int cut(int l, int r, vector<int>& cuts, vector<vector<int>>& dp) {
        if(r-1<=l) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        dp[l][r] = INT_MAX;
        for(int i=l+1; i<r; i++) {
            dp[l][r] = min(dp[l][r], cut(l, i, cuts, dp) + cut(i, r, cuts, dp) 
                           + cuts[r] -cuts[l]);
        }
        return dp[l][r];
    }
};