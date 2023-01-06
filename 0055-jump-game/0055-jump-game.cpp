class Solution {
public:
    vector<int> memo;
    bool checkCanJump(vector<int>& nums, int idx){
        if(idx==nums.size()-1)
            return true;
        
        if(memo[idx] != -1) return memo[idx];

        int reachable=idx+nums[idx];
        
        for(int k=idx+1;k<=reachable;k++)
            if(checkCanJump(nums, k))
                return memo[idx] = true;

        return memo[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        
        return checkCanJump(nums, 0);
    }
};