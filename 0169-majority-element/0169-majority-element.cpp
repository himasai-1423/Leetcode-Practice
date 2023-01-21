class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, res;
        
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                res = nums[i];
                count++;
            }
            
            else if(res == nums[i])
                count++;
            
            else
                count--;
        }
        return res;
    }
};