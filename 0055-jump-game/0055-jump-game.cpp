class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return jumpGame(nums, 0, dp);
    }
    
    bool jumpGame(vector<int> &nums, int i, vector<int> &dp){
        if(i==nums.size()-1)
            return true;
        
        if(dp[i] != -1) return dp[i];
        
        int goal = i+nums[i];
        
        for(int j = i+1; j<=goal; j++){
            if(jumpGame(nums, j, dp))
                return dp[i]= true;
        }
        return dp[i] = false;
    }
};