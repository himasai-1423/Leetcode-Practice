class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, sum=0, res=0;
        unordered_map<int,int> m;
        m[0]++;
        
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            sum = prefixSum - k;
            
            if(m.count(sum))
                res += m[sum];
            
            m[prefixSum]++;
        }
        return res;
    }
};