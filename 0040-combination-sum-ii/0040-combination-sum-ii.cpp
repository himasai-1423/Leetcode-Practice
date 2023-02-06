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
        
        int prev = -1;
        for(int i=idx; i<candidates.size(); i++){
            if(prev == candidates[i])
                continue;
            arr.push_back(candidates[i]);
            findVals(candidates, i+1, target-candidates[i], arr);
            arr.pop_back();
            prev = candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        
        sort(candidates.begin(), candidates.end());
        
        findVals(candidates, 0, target, arr);
        
        return res;
    }
};