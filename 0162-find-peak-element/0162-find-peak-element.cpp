class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return 0;
        
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        
        int hi=n-2, lo=1, mid;
        while(hi>=lo){
            mid = lo +(hi-lo)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]> nums[mid-1]) return mid;
            else if(nums[mid]<nums[mid-1]) hi = mid-1;
            else if(nums[mid] < nums[mid+1]) lo = mid+1;
        }
        return -1;
    }
};