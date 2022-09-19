class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=0;
        for(int i=0; i<k; i++)
            avg += nums[i];
        double maxi = avg/k;
        
        for(int i=k; i<nums.size(); i++){
            avg = avg + nums[i] - nums[i-k];
            maxi = max(maxi, avg/k);
        }
        return maxi;
    }
};