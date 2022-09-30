class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        {
//             sort(nums.begin(), nums.end());
//         int i=0;
    
//         while(i<nums.size() && nums[i]<1){
//             i++;
//         } 
        
//         int j=0;
//         for(; i<nums.size(); i++){
//             if(nums[i-1] != nums[i]) j++;
//             if(nums[i] != j) return j;
            
            
//         }
//         return j;
        }
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