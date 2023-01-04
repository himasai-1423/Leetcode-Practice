class Solution {
public:
    bool findPartition(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp){
        if(idx<0 || sum<0) return false;
        if(sum == 0) return true;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];     
        
        return dp[idx][sum] = findPartition(nums, idx-1, sum, dp) 
            || findPartition(nums, idx-1, sum-nums[idx], dp);;
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+5, vector<int>((100*nums.size())+5, -1));
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        
        if(sum%2 != 0) return false;
        
        return findPartition(nums, nums.size()-1, sum/2, dp);
    }
};