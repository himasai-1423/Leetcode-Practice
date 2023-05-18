class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="") return "";
        unordered_map<char, int> countT, countS;
        
        for(auto i: t)
            countT[i]++;
        
        int resLen = INT_MAX, l = 0, have = 0, need = countT.size();
        pair<int, int> resDim;
        for(int r = 0; r<s.size(); r++) {
            countS[s[r]]++;
            
            if(countT.count(s[r]) && countT[s[r]] == countS[s[r]])
                have++;
            
            while(have == need) {
                if(r-l+1<resLen) {
                    resDim = {l, r};
                    resLen = r-l+1;
                }
                countS[s[l]]--;
                
                if(countT.count(s[l]) && countS[s[l]]<countT[s[l]]) 
                    have--;
                                  
                l++;
            }
        }
        
        return (resLen==INT_MAX)?"":s.substr(resDim.first, resLen);
    }
};