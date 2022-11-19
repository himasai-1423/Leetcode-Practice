class Solution {
public:
    bool isPalindrome(string s) {
        int end = s.size()-1, start=0;
        
        while(start<end){
            if(!isalnum(s[start])) start++;
            else if(!isalnum(s[end])) end--;
            
            else{
                if(tolower(s[start++])!=tolower(s[end--])) 
                    return false;
            }          
        }
        return true;
    }
};