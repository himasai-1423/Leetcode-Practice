class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m1;
        multimap<int, int> m2;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++) 
            m1[nums[i]]++;
        
        for(auto &i: m1) 
            m2.insert({i.second, i.first});
        
        for(auto it = m2.rbegin(); it!=m2.rend(); it++) {
            k--;
            res.push_back(it->second);
            if(k==0)
                break;
        }
        return res;
    }
};