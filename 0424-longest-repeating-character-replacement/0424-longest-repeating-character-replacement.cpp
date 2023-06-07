class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> m;
        int maxf = 0, l = 0, res = 0;
        for(int i=0; i<s.size(); i++) {
            m[s[i]]++;
            maxf = max(maxf, m[s[i]]);
            
            if(i-l+1 - maxf > k) {
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;
    }
};