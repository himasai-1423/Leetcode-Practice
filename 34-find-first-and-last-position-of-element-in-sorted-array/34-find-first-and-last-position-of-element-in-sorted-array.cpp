class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int hi = n-1, lo =0, mid;
        vector<int> a(2,-1);
        while(hi>=lo){
            mid = lo + (hi-lo)/2;
            if(nums[mid]>target) hi = mid - 1;
            else if(nums[mid]<target) lo = mid +1;
            else{
                if(mid==lo || nums[mid] != nums[mid-1]){
                    a[0] = mid;
                    break;
                } 
                else{
                    a[0]= mid-1;
                    hi = mid-1;
                }
            }
        }
        
        hi = n-1, lo =0;
        while(hi>=lo){
            mid = lo + (hi-lo)/2;
            if(nums[mid]>target) hi = mid - 1;
            else if(nums[mid]<target) lo = mid +1;
            else{
                if(mid==hi || nums[mid] != nums[mid+1]){
                    a[1] = mid;
                    break;
                }
                else{
                    a[1]=mid+1;
                    lo=mid+1;
                }
            }
        }
        return a;
    }
};