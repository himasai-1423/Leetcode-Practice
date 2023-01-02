class Solution {
public:
    int dp[2510];
    int findLIS(vector<int> &nums, int n){
        int ans =1;
        
        if(dp[n] != -1) return dp[n];
        
        for(int i=0; i<n; i++){
            if(nums[i]<nums[n]){
                ans = max(ans, findLIS(nums, i)+1);
            }
        }
        return dp[n]= ans;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = max(ans, findLIS(nums, i));
        }
        
        return ans;
    }
};