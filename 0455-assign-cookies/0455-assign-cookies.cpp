class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0, i = 0, j = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(i<g.size() && j<s.size()) {
            if(g[i]<=s[j]) {
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};