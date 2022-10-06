class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int j=1, i=0, val=0;
    
        while(k && i<nums.size()){
            if(nums[i] != j){
                k--;
                val = j;
            }
        
            else
                i++;
            j++;
        }
        while(k){
            val = j;
            k--;
            j++;
        }
        return val;
    }
};