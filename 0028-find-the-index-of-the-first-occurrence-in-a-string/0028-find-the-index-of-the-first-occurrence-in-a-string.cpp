class Solution {
public:
    int hashFun(string s, int d, int MOD, int m) {
        int ans=0;
        long hshVal = 1;
        
        for(int i = m - 1; i >= 0; i--) {
            ans += ((int) (s[i]-'a')*hshVal)%MOD;
            hshVal = (hshVal*d)%MOD;
        }
        return ans%MOD;
    }
    
    int strStr(string haystack, string needle) {
        long hshVal = 1;
        int d=26, MOD=1e9+7;
        int m = needle.length(), n = haystack.length(); 
        if(n<m) return -1;
        
        for(int i=0; i<m; i++)
            hshVal = (hshVal*d)%MOD;
        
        long hayHsh=0, nHsh = hashFun(needle, d, MOD, m);
        
        for(int i=0; i<=n-m; i++) {
            if(i==0) 
                hayHsh = hashFun(haystack, d, MOD, m);
            
            else {
                hayHsh = ((hayHsh*d)%MOD - ((int)(haystack[i-1]-'a')*hshVal)%MOD + 
                    (int)(haystack[i+m-1]-'a')+MOD)%MOD;
            }
            
            if(hayHsh == nHsh) {
                for(int j=0; j<m; j++) {
                    if(needle[j] != haystack[i+j])
                        break;
                    
                    if(j==m-1)
                        return i;
                }
            }
        }
        return -1;
    }
};