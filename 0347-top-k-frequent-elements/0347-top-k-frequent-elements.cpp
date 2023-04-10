class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        multimap<int, int> freqK;
        
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        for(auto i: m) 
            freqK.insert({i.second, i.first});
        
        for(auto it = freqK.rbegin(); it!=freqK.rend(); it++) {
            if(k==0) break;
            
            res.push_back(it->second);
            k--;
        }
        return res;
    }
};