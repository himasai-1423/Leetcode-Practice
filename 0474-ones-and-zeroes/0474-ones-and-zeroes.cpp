class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(string s: strs){
            int numZeroes = 0, numOnes = 0;
    
            for (auto c : s) {
                if (c == '0')
	                numZeroes++;
                else if (c == '1')
	                numOnes++;
            }
            
            for(int zero=m; zero>=numZeroes; zero--){
                for(int one=n; one>=numOnes; one--){
                    dp[zero][one] = max(dp[zero - numZeroes][one-numOnes] + 1, dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
};