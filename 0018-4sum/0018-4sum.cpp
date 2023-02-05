class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void findKElements(vector<int> &nums, long long target, int k, int l, int r){
        if (k == 2) {
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    res.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    while (l + 1 < r && nums[l] == nums[l + 1])
                        ++l;
                    ++l;
                    // --r;
                } else if (nums[l] + nums[r] > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        while (l < r) {
            path.push_back(nums[l]);
            findKElements(nums, target - nums[l], k-1, l+1, r);
            path.pop_back();
            while (l + 1 < r && nums[l] == nums[l + 1])
                ++l;
            ++l;
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        if(nums.size()<4)
            return res;
        
        findKElements(nums, target, 4, 0, nums.size()-1);
        
        return res;
    }
};