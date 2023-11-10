class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0, res=1;
        while(j<nums.size()) {
            if(nums[i] != nums[j]) {
                nums[++i] = nums[j];
                res++;
            }    
            j++;
        }
        return res;
    }
};