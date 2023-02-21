class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int st = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='('){
                if(st)
                    res+='(';
                
                st++;
            }
            else if(s[i]==')'){
                if(st!=1)
                    res +=')';
                st--;                
            }
        }
        return res;
    }
};