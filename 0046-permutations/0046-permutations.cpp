class Solution {
public:
    vector<vector<int>> res;
    void swapPermute(vector<int> &nums, int idx){
        if(idx>=nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            swapPermute(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int> &nums) {
        swapPermute(nums, 0);
        return res;
    }
};