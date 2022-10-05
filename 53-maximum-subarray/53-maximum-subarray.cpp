class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0;
        int maxi=INT_MIN;
        for(auto i:nums)
        {
            cur+=i;
            maxi = max(maxi , cur);
            if(cur<0)
                cur=0;
        }
        return maxi;
    }
};