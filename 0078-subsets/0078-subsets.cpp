class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int powSet = (1<<n);
        
        for(int mask = 0; mask<powSet; mask++) {
            vector<int> ans;
            for(int i=0; i<n; i++) {
                if((mask&(1<<i)) != 0)
                    ans.push_back(nums[i]);
            }
            res.push_back(ans);
        }
        return res;
    }
};