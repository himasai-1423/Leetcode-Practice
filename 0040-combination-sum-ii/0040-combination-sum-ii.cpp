class Solution {
public:
    vector<vector<int>> res;
    
    void findVals(vector<int>& candidates, int idx, int target, vector<int> arr){
        if(target==0){
            res.push_back(arr);
            return;
        }
        
        if(target<0 || idx==candidates.size())
            return;
        
        arr.push_back(candidates[idx]);
        findVals(candidates, idx+1, target-candidates[idx], arr);
        arr.pop_back();
        
        int i = idx+1;
        while(i<candidates.size() && candidates[i]==candidates[i-1]) i++;
        
        findVals(candidates, i, target, arr);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        
        sort(candidates.begin(), candidates.end());
        
        findVals(candidates, 0, target, arr);
        
        return res;
    }
};