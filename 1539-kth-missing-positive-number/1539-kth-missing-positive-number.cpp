class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
//         int j=1, i=0, val=0;
    
//         while(k && i<nums.size()){
//             if(nums[i] != j){
//                 k--;
//                 val = j;
//             }
        
//             else
//                 i++;
//             j++;
//         }
//         while(k){
//             val = j;
//             k--;
//             j++;
//         }
//         return val;
        int n=nums.size();
        int x=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=nums[i]-x-1;
            x=nums[i];
            if(count>=k)
                return nums[i]-(count-k)-1;
        }
        return nums[n-1]+k-count;
    }
};