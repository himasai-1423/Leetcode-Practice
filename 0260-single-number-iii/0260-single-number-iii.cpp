class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(int &i: nums){
            if(m[i]==1) res.push_back(i);
        }
        return res;
    }
};