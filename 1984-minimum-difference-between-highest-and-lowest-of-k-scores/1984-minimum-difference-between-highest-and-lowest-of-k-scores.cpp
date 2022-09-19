class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int answer=INT_MAX;
        for(int i=0;i<nums.size()-k+1;i++){
            int val=nums[k+i-1]-nums[i];
            answer=min(answer,val);
        }
        return answer;
    }
};