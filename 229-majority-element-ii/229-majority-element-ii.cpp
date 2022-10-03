class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0, el1, el2;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else if(cnt1==0){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                el2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            } 
        }
        
        cnt1=0, cnt2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }

        if(cnt1>nums.size()/3) res.push_back(el1);
        if(cnt2>nums.size()/3) res.push_back(el2);
        
        return res;
    }
    
};