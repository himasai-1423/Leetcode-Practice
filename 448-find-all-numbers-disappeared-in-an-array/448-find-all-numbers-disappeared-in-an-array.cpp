class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> ret;
        
        set<int>::iterator it;
        int i=1, n=nums.size();
        for(it=s.begin(); it!=s.end();){
            if(*it==i){
                it++;
                i++;
            } else {
                ret.push_back(i);
                i++;
            }
        }
        
        while(i<=n){
            ret.push_back(i);
            i++;
        }
        
        return ret;
    }
};