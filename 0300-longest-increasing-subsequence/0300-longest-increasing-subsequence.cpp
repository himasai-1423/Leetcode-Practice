class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for(int i=0; i<nums.size(); i++) {
            auto ele = lower_bound(dp.begin(), dp.end(), nums[i]);
            
            if(ele==dp.end()) 
                dp.push_back(nums[i]);
            
            else
                *ele = nums[i];
        }
        return dp.size();
    }
};