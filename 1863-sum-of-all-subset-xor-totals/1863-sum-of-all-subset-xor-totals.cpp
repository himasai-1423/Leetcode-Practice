class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        int maskSize = (1<<nums.size());
        for(int mask=0; mask<maskSize; mask++){
            int ans=0;
            for(int i=0; i<nums.size(); i++)
                if((mask & (1<<i))!=0)
                    ans ^= nums[i];
            res += ans;
        }
        return res;
    }
};