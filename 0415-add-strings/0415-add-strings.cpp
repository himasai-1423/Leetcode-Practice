class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1, j = num2.size()-1, carry=0;
        string res="";
        
        while(i>=0 || j>=0 || carry){
            int val = 0;
            if(i>=0)
                val = num1[i] - '0';
            
            if(j>=0)
                val += num2[j] - '0';
            
            val += carry;
            carry = val/10;
            val = val%10 + '0';
            
            res.push_back(val);
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};