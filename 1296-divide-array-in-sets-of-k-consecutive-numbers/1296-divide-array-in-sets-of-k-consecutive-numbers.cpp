class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        
        if(nums.size()%k!=0) return false;
        
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;
        
        int len = (nums.size())/k;
        
        for(int i=0; i<len; i++){
            auto it = m.begin();
            int temp = it->first;
            
            for(int j=temp; j<temp+k; j++){
                if(m.find(j)==m.end())
                    return false;
                
                m[j]--;
                if(m[j]==0)
                    m.erase(j);
            }
        }
        return true;
    }
};