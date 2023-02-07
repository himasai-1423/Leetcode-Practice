class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1;
        
        for(int i=0; i<ransomNote.size(); i++)
            m1[ransomNote[i]]++;
        
        for(int i=0; i<magazine.size(); i++){
            if(m1.count(magazine[i]))
                m1[magazine[i]]--;
            
            if(m1[magazine[i]]==0)
                m1.erase(magazine[i]);
        }
        if(m1.empty())
            return true;
        
        return false;
    }
};