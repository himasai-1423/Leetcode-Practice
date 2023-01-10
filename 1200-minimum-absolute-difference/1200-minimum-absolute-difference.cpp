class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        
        sort(arr.begin(), arr.end());
        
        int mini = INT_MAX;
        for(int i=1; i<arr.size(); i++)
            mini = min(arr[i]-arr[i-1], mini);
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1] == mini){
                vector<int> vec;
                vec.push_back(arr[i-1]);
                vec.push_back(arr[i]);
                res.push_back(vec);
            }
        }
        return res;
    }
};