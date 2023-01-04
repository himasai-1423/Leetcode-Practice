class Solution {
public:
    bool findPartition(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp){
        if(idx<0) return false;
        if(sum == 0) return true;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool parti = findPartition(nums, idx-1, sum, dp);
        
        if(sum-nums[idx]>=0)
        parti |= findPartition(nums, idx-1, sum-nums[idx], dp);
        
        return dp[idx][sum] = parti;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+5, vector<int>((100*n)+5, -1));
        int sum =0; 
        
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        
        return findPartition(nums, n-1, sum/2, dp);
    }
};