class Solution {
public:
    int houseRob(vector<int>& nums, int idx, vector<int> &dp){
        if(idx>=nums.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int steal = nums[idx] + houseRob(nums, idx+2, dp);
        int skip = houseRob(nums, idx+1, dp);
        
        return dp[idx]=max(steal, skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return houseRob(nums, 0, dp);
    }
};