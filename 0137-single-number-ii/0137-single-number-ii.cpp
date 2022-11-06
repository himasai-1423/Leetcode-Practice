class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(int &i: nums){
            if(m[i]==1) return i;
        }
        return -1;
    }
};