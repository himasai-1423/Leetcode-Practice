class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left=0, right=n, mid=0;
         while(left<right){
             mid = (left + right)/2;
             if(nums[mid]>mid) right = mid;
             else left = mid+1;
        }
        return left;
    }
};