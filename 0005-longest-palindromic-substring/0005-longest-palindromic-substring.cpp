class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int strLen=0;
        
        for(int i=0; i<s.size(); i++){
            int l = i, r = i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>strLen){
                    strLen=r-l+1;
                    res = s.substr(l, strLen);
                }
                l--;
                r++;
            }
            
            l = i, r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>strLen){
                    strLen=r-l+1;
                    res = s.substr(l, strLen);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};