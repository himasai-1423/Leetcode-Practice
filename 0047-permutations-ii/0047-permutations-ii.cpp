class Solution {
public:
    set<vector<int>> ans;
    void swapPermute(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            ans.insert(nums);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            swapPermute(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        swapPermute(nums, 0);
        vector<vector<int>> res;
        
        for(auto i: ans) 
            res.push_back(i);
        
        return res;        
    }
};