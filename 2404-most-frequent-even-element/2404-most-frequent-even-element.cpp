class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        
        for(int i=0; i<nums.size(); i++){
            if(!(nums[i]&1)){
                m[nums[i]]++;
            }
        }
        
        int res = -1 , freq = INT_MIN;
        for(auto i: m){
            if(i.second>freq)
                res = i.first, freq=i.second;
        }
        
        return res;
    }
};