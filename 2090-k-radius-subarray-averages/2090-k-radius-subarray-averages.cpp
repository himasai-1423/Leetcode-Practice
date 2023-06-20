class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        if(k == 0)
            return nums;
        
        if(2*k+1 > n)
            return res;
        
        long long window = 0;
        for(int i=0; i<(2*k+1); i++)
            window += nums[i];
        
        res[k] = window/(2*k+1);
        
        for(int i=(2*k+1); i<n; i++) {
            window = window + nums[i] - nums[i-(2*k+1)];
            res[i-k] = window/(2*k+1);
        }
        return res;
    }
};