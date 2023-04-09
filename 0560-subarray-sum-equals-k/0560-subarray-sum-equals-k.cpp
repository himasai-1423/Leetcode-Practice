class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]++;
        
        int sum = 0, res=0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int curSum = sum - k;
            
            if(m.count(curSum)) 
                res += m[curSum];
            
            m[sum]++;
        }
        return res;
    }
};