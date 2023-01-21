class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0, res1, res2;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            if(res1 == nums[i])
                cnt1++;
            
            else if(res2 == nums[i])
                cnt2++;
            
            else if(cnt1==0){
                res1 = nums[i];
                cnt1++;
            }
            
            else if(cnt2 == 0){
                res2 = nums[i];
                cnt2++;
            }
            
            else{
                cnt2--;
                cnt1--;
            }
        }
        cnt1=0;
        cnt2=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==res1)
                cnt1++;
            
            else if(nums[i]==res2)
                cnt2++;
        }
        
        if(cnt1>nums.size()/3 && cnt2>nums.size()/3){
            res.push_back(res1);
            res.push_back(res2);
        }
        
        else if(cnt1>nums.size()/3)
            res.push_back(res1);
        
        else if(cnt2>nums.size()/3)
            res.push_back(res2);
        
        return res;
    }
};