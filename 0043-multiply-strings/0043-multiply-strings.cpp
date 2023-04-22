class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> res(n+m, 0);
        string ans="";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int a = num1[i]-'0';
                int b = num2[j]-'0', c;
                c = res[i+j]+a*b;
                
                res[i+j] = c%10;
                res[i+j+1] += c/10;
            }
        }
        reverse(res.begin(), res.end());
        
        for(int i=0; i<res.size(); i++) {
            if(ans=="" && res[i]==0) continue;

            ans += (res[i]+'0');
        }
        return ans==""?"0":ans;
    }
};