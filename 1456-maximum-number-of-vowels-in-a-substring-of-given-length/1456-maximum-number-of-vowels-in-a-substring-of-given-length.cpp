class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 1, r = 0, res = 0, cnt = 0;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        for(int i=0; i<k; i++) 
            if(st.count(s[i]))
                cnt++;
        
        res = cnt;
        r = k;
        while(r<s.size()) {
            if(st.count(s[l-1])) 
                cnt--;

            if(st.count(s[r]))
                cnt++;

            res = max(res, cnt);
            r++;
            l++;
        }
        return res;
    }
};