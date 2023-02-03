class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=1; i<nums.size(); i++){
            int l=0, r=i;
            while(l<r){
                int mid = l+(r-l)/2;
                if(nums[mid]==target-nums[i])
                    return {mid+1, i+1};
                else if(nums[mid]>target-nums[i])
                    r = mid;
                else
                    l = mid+1;
            }
        }
        return {};
    }
};