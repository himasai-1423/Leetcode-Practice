class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        
        for(int i=0; i<order.size(); i++)
            m[order[i]]= i+1;
        
        for(int i=0; i<words.size()-1; i++){
            for(int j=0; j<words[i].size(); j++){
                if(j>=words[i+1].size()) return false;
                
                if(m[words[i][j]]>m[words[i+1][j]]) return false;
                if(m[words[i][j]]<m[words[i+1][j]]) break;
            }
        }
        return true;
    }
};