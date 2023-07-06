class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX, curSum = 0, l=0;
        
        for(int i=0; i<nums.size(); i++) {
            curSum += nums[i];
            
            while(curSum>=target) {
                minLen = min(minLen, i-l+1);
                curSum -= nums[l];
                l++;
            }   
        }
        return minLen==INT_MAX?0:minLen;
    }
};