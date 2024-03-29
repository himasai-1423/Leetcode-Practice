class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0, res = 0;
        for(int r=0; r<s.size(); r++) {
            m[s[r]]++;
            while(m[s[r]]>1) {
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};