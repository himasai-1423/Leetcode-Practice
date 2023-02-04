class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int j = i+1, k=nums.size()-1, sum;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j<k && nums[j] == nums[j-1])
                        j++;
                }
                
                else if(sum > 0)
                    k--;
                
                else if(sum<0)
                    j++;
            }
        }
        return res;
    }
};