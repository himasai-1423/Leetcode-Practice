class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> resCorrect;
        sort(nums.begin(), nums.end());
        int n = (1<<nums.size());
        for(int mask=0; mask<n; mask++){
            vector<int> ans;
            for(int i=0; i<nums.size(); i++)
                if((mask&(1<<i))!=0)
                    ans.push_back(nums[i]);
            resCorrect.insert(ans);
        }
        
        for(auto i: resCorrect){
            res.push_back(i);
        }
        return res;
    }
};