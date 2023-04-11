class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        
        for(auto &ch: s) {
            if(ch=='*') j--;
            else {
                s[j] = ch;
                j++;
            }
        }
        return s.substr(0, j);
    }
};