class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest=nums[0]+nums[1]+nums[2];
        sort(begin(nums), end(nums));
        
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int hi=nums.size()-1, lo=i+1;
            while(hi>lo){
                int sum = nums[i]+nums[hi]+nums[lo];
                if(sum==target) return sum;
                
                if(abs(target-sum)<abs(target-closest)) 
                    closest = sum;

                if(sum>target) hi--;
                else lo++;
            }
        }
        return closest;
    }
};