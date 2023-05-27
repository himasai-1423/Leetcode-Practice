class Solution {
public:
    int dfs(int isAlice, int i, int M, 
            vector<vector<vector<int>>> &dp, vector<int> &piles) {
        if(i==piles.size()) return 0;
        
        if(dp[isAlice][i][M] != -1) return dp[isAlice][i][M];
        
        int res = isAlice?0:INT_MAX;
        int total = 0;
        for(int idx= 1; idx<=2*M; idx++) {
            if(idx+i>piles.size())
                break;
            total += piles[idx + i -1];
            if(isAlice == 1)
                res = max(res, total + dfs(0, i+idx, max(M, idx), dp, piles));
            
            else
                res = min(res, dfs(1, i+idx, max(M,idx), dp, piles));
        }
        dp[isAlice][i][M] = res;
        return res;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(2, 
                vector<vector<int>>(piles.size()+1, 
                        vector<int>(piles.size()+1, -1)));
        
        return dfs(1, 0, 1, dp, piles);
    }
};