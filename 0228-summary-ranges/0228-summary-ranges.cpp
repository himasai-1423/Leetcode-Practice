class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n= nums.size();
        string temp= "";
        vector<string> res;
        int j;
        for(int i=0; i<n; i++){
            j=i;
            while(j+1<n && nums[j+1]== nums[j]+1) j++;
            
            if(j>i){
                temp+= to_string(nums[i]);
                temp+="->";
                temp+=to_string(nums[j]);
            }
            else{
                temp = to_string(nums[i]);
            }
            res.push_back(temp);
            temp="";
            i=j;
        }
        return res;
    }
};