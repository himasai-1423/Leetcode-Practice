class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int res = 1;
        for(char i: s) {
            if(st.count(i)) {
                st.clear();
                res++;
            }
            st.insert(i);
        }
        return res;
    }
};