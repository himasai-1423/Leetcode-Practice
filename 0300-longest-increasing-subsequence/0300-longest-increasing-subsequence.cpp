class Solution {
public:    
    int findLen(vector<int>& nums, vector<int>& dp, int idx) {
        if(idx<0) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int ans = 1;
        for(int i = idx; i>=0; i--) 
            if(nums[i]<nums[idx]) 
                ans = max(ans, 1 + findLen(nums, dp, i));
            
        return dp[idx]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int res = 1;
        for(int i = nums.size()-1; i>=0; i--) {
            res = max(res, findLen(nums, dp, i));
        }
        
        return res;
    }
};