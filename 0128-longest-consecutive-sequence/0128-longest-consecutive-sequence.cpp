class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0, cnt = 1, val = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == val+1)
                cnt++;
            
            else if(nums[i]==val)
                continue;
                
            else
                cnt = 1;
            
            val = nums[i];
            res = max(res, cnt);
        }
        return res;
    }
};