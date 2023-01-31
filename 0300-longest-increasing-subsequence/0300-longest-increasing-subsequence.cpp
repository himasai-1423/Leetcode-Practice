class Solution {
public:
    int findLIS(vector<int> &nums, int idx, vector<int> &dp){
        int ans =1;
        
        if(dp[idx]!=-1) return dp[idx];
        for(int i=0; i<idx; i++)
            if(nums[i]<nums[idx])
                ans = max(ans, findLIS(nums, i, dp)+1);
        
        return dp[idx]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int res = 0;
        
        for(int i=0; i<nums.size(); i++){
            res = max(res, findLIS(nums, i, dp));
        }
        return res;
    }
};