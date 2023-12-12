class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0, secMaxi = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>maxi) {
                secMaxi = maxi;
                maxi = nums[i];
            } else {
                secMaxi = max(secMaxi, nums[i]);
            }
        }
        return (maxi-1)*(secMaxi-1);
    }
};