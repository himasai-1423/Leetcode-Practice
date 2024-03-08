class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxFreq=0, res=0;
        
        for(int i=0; i<nums.size(); i++) 
            m[nums[i]]++;
        
        for(auto i: m) {
            maxFreq = max(maxFreq, i.second);
        }
        
        for(auto i: m) {
            if(i.second == maxFreq) 
                res += maxFreq;
        }
        
        return res;
    }
};