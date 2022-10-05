class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0];
        int slow=nums[0];
        
        do{
            fast=nums[nums[fast]];
            slow=nums[slow];
        }while(fast!=slow);
        
        int slow2=nums[0];
        
        while(slow!=slow2){
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
    }
};