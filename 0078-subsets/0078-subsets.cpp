class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int maskSize = (1<<nums.size());
        for(int mask=0; mask<maskSize; mask++){
            vector<int> ans;
            for(int i=0; i<nums.size(); i++)
                if((mask & (1<<i))!=0)
                    ans.push_back(nums[i]);
            res.push_back(ans);
        }
        return res;
    }
};