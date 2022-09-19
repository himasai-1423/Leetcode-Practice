class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=0, maxi=INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(i<k) {
                avg+=nums[i];
                maxi = avg/k;
            }
            
            else{
                avg = avg + nums[i] - nums[i-k];
                maxi = max(maxi, avg/k);
            } 
        }
        return maxi;
    }
};