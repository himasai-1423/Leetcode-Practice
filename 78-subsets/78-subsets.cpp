class Solution {
public:
    vector<vector<int>> res;
    
    void generate(vector<int> &nums, int i, vector<int> &subarray){
        if(i==nums.size()){
            res.push_back(subarray);
            return;
        }
        generate(nums, i+1, subarray);
        
        subarray.push_back(nums[i]);
        generate(nums, i+1, subarray);
        subarray.pop_back();
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subarray;
        generate(nums, 0, subarray);
        return res;
    }
};