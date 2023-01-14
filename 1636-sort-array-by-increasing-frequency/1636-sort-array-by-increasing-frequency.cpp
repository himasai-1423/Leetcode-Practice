class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        
        for(int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        
        sort(begin(nums), end(nums), [&](int a, int b){
            return count[a]==count[b]?a>b:count[a]<count[b];
        });
        
        return nums;
    }
};