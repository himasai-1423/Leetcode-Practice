class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        for(int i=0; i<s.size(); i++) {
            char front_char = s[0];
            s = s.substr(1);
            s += front_char;
            if(s == goal) {
                return true;
            }
        }
        
        return false;
    }
};