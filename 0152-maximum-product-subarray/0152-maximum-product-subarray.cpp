class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = 1, maxi=1, res=INT_MIN;
        
        for(int i : nums){
            if(i==0){
                mini=maxi=1;
            }
                
            int temp = maxi * i;
            
            maxi = max({temp, mini*i, i});
            mini = min({temp, mini*i, i});
            res = max(res, maxi);
        }
        return res;
    }
};