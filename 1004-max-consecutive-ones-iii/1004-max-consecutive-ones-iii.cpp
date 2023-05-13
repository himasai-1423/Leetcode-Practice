class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0, l = 0;
        
        while(r<nums.size()) {
            if(nums[r]==0) k--;
            
            if(k<0) {
                if(nums[l]==0)
                    k++;
                l++;
            }
            r++;
        }
        
        return r-l;
    }
};