class Solution {
public:
    vector<vector<int>> res;
    void generateSubsets(vector<int> &nums, vector<int> ans, int i, bool pre){
        if(i==nums.size()){
            res.push_back(ans);
            return;
        }
        generateSubsets(nums, ans, i+1, false);        
        
        if(i>0 && nums[i]==nums[i-1] && !pre) return;
        
        ans.push_back(nums[i]);
        generateSubsets(nums, ans, i+1, true);
        ans.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(begin(nums), nums.end());
        generateSubsets(nums, ans, 0,  true);
        return res;
    }
};