class Solution {
public:
    unordered_map<char, int> m = {{'(', 1}, {'{', 2}, {'[', 3}, 
                                  {')', -1}, {'}', -2}, {']', -3}};
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s) {
            if(m[ch]>0) {
                st.push(m[ch]);
            }
            else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(top + m[ch] != 0)
                    return false;
            }
        }
        return st.empty();
    }
};