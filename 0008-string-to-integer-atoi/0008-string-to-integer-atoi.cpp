class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign=1, res=0;
        
        while(s[i]==' ') i++;
        if(s[i]=='+' || s[i]=='-') {
            if(s[i]=='-')
                sign = -1;
            i++;
        }
        
        const int maxLimit = INT_MAX / 10;
        while(i<s.size() && (s[i]>='0' && s[i]<='9')) {
             if(res>maxLimit || (res == maxLimit &&  s[i] - '0' > 7))
                return sign>0?INT_MAX:INT_MIN;
            res = res*10 + (s[i] - '0');
            i++;
        }
        return sign*res;
    }
};