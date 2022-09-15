class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(int &i: nums){
            s.insert(i);
        }
        
        int n = nums.size();
        int loc = n - k;
        
        for(auto &i: s){
            if(loc==0) return i;
            
            loc--;
        }
        return -1;
    }
};