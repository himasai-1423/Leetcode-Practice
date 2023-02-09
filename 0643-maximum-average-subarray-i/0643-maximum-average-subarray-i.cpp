class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0, sum=0;
        
        for(int i=0; i<k; i++)
            sum += nums[i];
        
        res = sum/k;
        for(int i=k; i<nums.size(); i++){
            sum += (nums[i] - nums[i-k]);
            res = max(res, sum/k);
        }
        return res;        
    }
};