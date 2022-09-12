class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size()-1, lo=0, mid, realmid, n=nums.size();
        while(hi>lo){
            mid = lo + (hi-lo)/2;
            
            if(nums[mid]>nums[hi]) lo = mid+1;
            else hi = mid;
        }
        int k= lo;
        
        hi = nums.size()-1, lo=0;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            int realmid= (mid+k)%n;
            if(nums[realmid]==target) return realmid;
            else if(nums[realmid]<target) lo = mid+1;
            else hi = mid-1;
        }
        
        return -1;
    }
};