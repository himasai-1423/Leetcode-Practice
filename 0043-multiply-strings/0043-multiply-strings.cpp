class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") 
            return "0";

        string res(num1.size()+num2.size(), '0');        
        for(int i = num1.size()-1; i>=0; i--) {
            for(int j = num2.size()-1; j>=0; j--) {
                int a = num1[i]-'0';
                int b = num2[j]-'0', c;
                c = (res[i+j+1]-'0')+a*b;
                
                res[i+j+1] = c%10 + '0';
                res[i+j] += c/10;
            }
        }
        if(res[0] == '0') return res.substr(1);
        return res;
    }
};