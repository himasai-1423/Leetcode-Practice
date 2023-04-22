class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, -1));
        vector<int> arr;
        
        arr.push_back(1);
        for(int i=0; i<nums.size(); i++)
            arr.push_back(nums[i]);
        arr.push_back(1);
        
        int res = dfs(arr, 1, arr.size()-2, dp);
        
        for(int i = 0; i<dp.size(); i++){
            for(int j= 0; j<dp[0].size(); j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return res;   
    }
    
    int dfs(vector<int> &arr, int l, int r, vector<vector<int>> &dp){
        if(l>r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int coins = 0; 
        for(int i=l; i<=r; i++){
            coins = arr[l-1]*arr[i]*arr[r+1];
            coins += dfs(arr, i+1, r, dp) + dfs(arr, l, i-1, dp);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];
    }
};