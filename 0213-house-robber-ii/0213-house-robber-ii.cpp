class Solution {
public:
    int robHouse(vector<int> &nums, int idx, vector<int> &dp){
        if(idx>=nums.size())
            return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int stealHouse = nums[idx] + robHouse(nums, idx+2, dp);
        int skipHouse = 0 + robHouse(nums, idx+1, dp);
        
        return dp[idx] = max(stealHouse, skipHouse);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        //if(nums.size()==2) return max(nums[1], nums[0]);
        
        vector<int> dp(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        
        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);
        
        return max(robHouse(nums1, 0, dp), robHouse(nums2, 0, dp2));
    }
};