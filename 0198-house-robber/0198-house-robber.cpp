class Solution {
public:
    int houseRobber(int i, vector<int> &nums, vector<int> &dp) {
        if(i>=nums.size()) 
            return 0;
        
        if(dp[i] != -1) return dp[i];
        int robbed = nums[i] + houseRobber(i+2, nums, dp);
        int skipped = houseRobber(i+1, nums, dp);
        
        return dp[i] = max(robbed, skipped);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return houseRobber(0, nums, dp);
    }
};