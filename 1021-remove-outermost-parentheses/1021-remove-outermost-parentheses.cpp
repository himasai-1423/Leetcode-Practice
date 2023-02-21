class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        stack<int> st;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='('){
                if(!st.empty()){
                    res+='(';
                    st.push(i);
                }
                
                else
                    st.push(i);
                
            }
            else if(s[i]==')'){
                if(st.size()==1)
                    st.pop();
                
                else{
                    res+=')';
                    st.pop();
                }
            }
        }
        return res;
    }
};