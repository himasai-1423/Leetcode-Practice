class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return;
        
        int lo =0, hi = nums.size()-1, mid = 0;
        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums, mid, lo);
                mid++;
                lo++;
            }
            
            else if(nums[mid]==1){
                mid++;
            }
            
            else{
                swap(nums, hi, mid);
                hi--;
            }
        }
    }
};