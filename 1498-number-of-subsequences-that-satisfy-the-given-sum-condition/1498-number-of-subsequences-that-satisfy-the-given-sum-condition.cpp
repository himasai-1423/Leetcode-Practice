class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> pow(nums.size(), 1);
        
        for(int i=1; i<nums.size(); i++) 
            pow[i] = (pow[i-1]*2)%MOD;
        
        int l = 0, r = nums.size()-1;
        int res = 0;
        
        while(l<=r) {
            if(nums[l] + nums[r] <= target) {
                res = (res + pow[r-l])%MOD; 
                l++;
            }
            else
                r--;
        }
        return res;
    }
};