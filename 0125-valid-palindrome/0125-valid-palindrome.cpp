class Solution {
public:
    bool isPalindrome(string s) {
        string str= "";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])) str.push_back(tolower(s[i]));
        }
        
        int n = str.size();
        for(int i=0; i<n/2; i++){
            if(str[i] != str[n-1-i])
                return false;
        }
        return true;
    }
};