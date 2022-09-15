class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int hi = n-1, lo =0, mid, val, realMid;
        
        while (hi>lo){
            mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        val = lo;
        hi = n-1, lo =0;
        while(hi>=lo){
            mid = lo + (hi-lo)/2;
            realMid = (mid + val)%n;
            
            if(nums[realMid] == target) return realMid;
            else if(nums[realMid]>target) hi = mid-1;
            else lo = mid + 1;
        }
        return -1;
    }
};