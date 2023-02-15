class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry = 0, i=num.size()-1, val = k;
        while(i>=0 || val){
            if(i>=0)
                val += num[i];
            
            res.push_back(val%10);
            val /= 10;
            i--;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};