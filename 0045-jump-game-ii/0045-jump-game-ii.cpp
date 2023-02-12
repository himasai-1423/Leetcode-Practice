class Solution {
public:
    int jump(vector<int>& nums) {
        int maxDistReached =0, currDist=0, res=0;
        
        for(int i=0; i<nums.size()-1; i++){
            currDist = max(nums[i]+i, currDist);                
            
            if(i==maxDistReached){
                res++;
                maxDistReached = currDist;
            }
        }
        return res;
    }
};