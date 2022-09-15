class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int hi = nums.size()-1, lo = 0, mid;
        while(hi>lo){
            mid = lo + (hi-lo)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2!=0 && nums[mid] == nums[mid-1] ))
               lo = mid+1;
               
            else
               hi = mid;
        }
        return nums[lo];
    }
};