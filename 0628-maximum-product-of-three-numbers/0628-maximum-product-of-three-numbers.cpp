class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res1 = 1, res2=1;
        int n = nums.size();
        
        res1 *= nums[n-1]*nums[n-2]*nums[n-3];
        res2 *= nums[0]*nums[1]*nums[n-1];
        
        return max(res1, res2);
    }
};