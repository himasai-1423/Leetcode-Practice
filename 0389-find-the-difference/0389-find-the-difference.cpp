class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mS, mT;
        
        for(int i=0; i<s.size(); i++)
            mS[s[i]]++;
        
        for(int i=0; i<t.size(); i++)
            mT[t[i]]++;
        
        for(auto i : mT){
            if(mS.find(i.first) == mS.end())
                return i.first;
            
            else if(mS[i.first] != i.second)
                return i.first;
        }
        
        return ' ';
    }
};