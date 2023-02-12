class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> m1, m2;
        
        for(int i=0; i<word1.size(); i++)
            m1[word1[i]]++;
        
        for(int i=0; i<word2.size(); i++)
            m2[word2[i]]++;
        
        if(m1.size()==m2.size() && word1.size()==word2.size()) 
            return true;
        
        for(char i ='a'; i<='z'; i++){
            for(char j='a'; j<='z'; j++){
                if(m1.count(i) && m2.count(j)){
                    m1[i]--;
                    if(m1[i]==0) m1.erase(i);
                    m1[j]++;
                    
                    m2[j]--;
                    if(m2[j]==0) m2.erase(j);
                    m2[i]++;
                    
                    if(m1.size()==m2.size())
                        return true;
                    
                    m1[j]--;
                    if(m1[j]==0) m1.erase(j);
                    m2[i]--;
                    if(m2[i]==0) m2.erase(i);
                    
                    m1[i]++;
                    m2[j]++;
                }
            }
        }
        return false;
    }
};