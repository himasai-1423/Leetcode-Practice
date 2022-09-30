class Solution {
public: 
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) s.insert(nums[i]);
        }
        
        int j=1;
        for(auto &i : s){
            if(i != j) return j;
            j++;
        }
        return j;
    }
};