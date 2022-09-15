class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int &i: nums){
            m[i]++;
        }
        
        for(auto &j: m){
            if(j.second == 1) return j.first;
        }
        return -1;
    }
};