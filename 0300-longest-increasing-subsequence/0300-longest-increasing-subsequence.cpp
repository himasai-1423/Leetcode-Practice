class Solution {
public:
    int LIS(vector<int> &nums, int idx, vector<int> &dp){
        if(idx<0) return 0;
        
        int ans = 1;
        
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=idx-1; i>=0; i--){
            if(nums[idx]>nums[i])
                ans = max(ans, LIS(nums, i, dp)+1);
        }
        
        return dp[idx] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size()+2, -1);
        
        for(int i=nums.size()-1; i>=0; i--){
            res = max(res, LIS(nums, i, dp)); 
        }
        return res;
    }
};