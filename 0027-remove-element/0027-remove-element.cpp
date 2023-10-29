class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0, marker = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == val) {
                cnt++;
                continue;
            }
            nums[marker] = nums[i];
            marker++;
        }
        return nums.size()-cnt;
    }
};