class Solution {
public:
    unordered_map<char, int>  m = {{'(', 1}, {'[', 2},{'{', 3},
                                   {')', -1},{']', -2},{'}', -3}};
    bool isValid(string s) {
        stack<char> st;
        for(char i: s) {
            if(m[i]>0) 
                st.push(m[i]);
            
            else {
                if(st.empty()) return false;
                
                int up = st.top();
                st.pop();
                
                if(up + m[i]!=0)
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};