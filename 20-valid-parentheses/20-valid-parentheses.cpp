class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> m={{'(',-1}, {'{',-2}, {'[',-3}, {')',1}, {'}',2}, {']',3}};
        stack<int> st;
        char up;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(m[s[i]]<0) st.push(s[i]);
            
            else{
                if(st.empty()) return false;
                up = st.top();
                st.pop();
                if(m[up] + m[s[i]] != 0) return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};