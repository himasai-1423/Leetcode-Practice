class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        int n = (1<<nums.size());
        for(int i=0; i<n; i++){
            int XORsum = 0;
            for(int j=0; j<nums.size(); j++)
                if((i & (1<<j))!=0)
                    XORsum ^= nums[j];
            res+=XORsum;
        }
        return res;
    }
};