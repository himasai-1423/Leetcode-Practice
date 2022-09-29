class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        int cnt =1;
        
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int limi = s.size()-2;
        if(s.size()<3){
            int ele = *(--(s.end()));
            //cout<<"Returning if"<<endl;
            return ele;
        }
        
        else{
           for(auto i:s){
               //cout<<"Returning else "<<limi<<endl;
               if(cnt==limi) return i;
               cnt++;
           }
        }
        return -1;
    }
};