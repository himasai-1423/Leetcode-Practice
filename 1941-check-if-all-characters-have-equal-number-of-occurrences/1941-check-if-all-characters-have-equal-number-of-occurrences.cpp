class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        
        for(int i=0; i<s.size(); i++)
            m[s[i]]++;
        
        int check = m.begin()->second;
        
        for(auto &i: m)
            if(i.second!=check)
                return false;
        
        return true;
    }
};