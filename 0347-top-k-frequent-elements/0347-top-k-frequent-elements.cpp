class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        multimap<int, int> m2;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) 
            m[nums[i]]++;
        
        for(auto i: m)
            m2.insert({i.second, i.first});
        
        for(auto it = m2.rbegin(); it!=m2.rend(); it++) {
            if(k==0)
                break;
            res.push_back(it->second);
            k--;
        }
        return res;
    }
};