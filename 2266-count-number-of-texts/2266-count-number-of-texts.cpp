class Solution {
public:
    int countTexts(string pressedKeys) {
        int dp[5] = {1, 1, 1, 1, 1};
        int n = pressedKeys.size();
        
        for(int i=n-1; i>=0; i--){
            dp[i%5] = 0;
            int maxJ= min(n, i+(pressedKeys[i]=='7'||pressedKeys[i]=='9'?4:3));
            
            for(int j=i; j<maxJ && pressedKeys[i]==pressedKeys[j]; j++){
                dp[i%5] = (dp[i%5] + dp[(j+1)%5])%1000000007;
            }
        }
        return dp[0];
    }
};