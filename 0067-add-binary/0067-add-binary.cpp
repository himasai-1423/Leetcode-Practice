class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        
        int i=a.size()-1;
        int j=b.size()-1;
        
        int carry = 0;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0)
                sum+= a[i] - '0';
            
            if(j>=0)
                sum+= b[j] - '0';
            
            res += (sum%2)+'0';
            carry = sum/2 ;
            
            i--;
            j--;
        }
        
        if(carry != 0) res+='1';
        
        reverse(begin(res), end(res));
        // res = to_string(res);
        
        return res;
    }
};