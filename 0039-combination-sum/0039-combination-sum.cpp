class Solution {
public:
    vector<vector<int>> res;
    void fillArrays(vector<int>& candidates, int idx, vector<int> arr, int target){
        if(target==0){
            res.push_back(arr);
            return;
        }
        
        if(idx==candidates.size() || target<0)
            return;
        
        arr.push_back(candidates[idx]);
        fillArrays(candidates, idx, arr, target-candidates[idx]);
        arr.pop_back();
        
        fillArrays(candidates, idx+1, arr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currArr;
        
        fillArrays(candidates, 0, currArr, target);
        return res;
    }
};