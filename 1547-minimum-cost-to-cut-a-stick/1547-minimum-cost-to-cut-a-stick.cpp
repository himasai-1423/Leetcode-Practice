class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size()+2, vector<int>(cuts.size()+2));
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        return dfs(cuts, 0, cuts.size()-1, dp);
    }
    
    int dfs(vector<int>& cuts, int l, int r, vector<vector<int>> &dp){
        if(r-l<=1) return 0;
        
        if(!dp[l][r]){
            dp[l][r] = INT_MAX;
            for(int i=l+1; i<r; i++){           
                dp[l][r] = min(dp[l][r], dfs(cuts, l, i, dp) +
                               dfs(cuts, i, r, dp) + cuts[r]-cuts[l]);
            }
        }
        return dp[l][r];
    }
};