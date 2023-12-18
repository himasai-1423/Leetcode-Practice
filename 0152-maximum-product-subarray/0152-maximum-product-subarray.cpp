class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = 1, maxi = 1, res = INT_MIN;
        
        for(int i: nums) {
            if(i==0) {
                mini=maxi=1;
                res=max(res, 0);
                continue;
            }
            
            int temp = i*maxi;
            maxi = max({temp, i*mini, i});
            mini = min({temp, i*mini, i});
            
            res = max(res, maxi);
        }
        return res;
    }
};