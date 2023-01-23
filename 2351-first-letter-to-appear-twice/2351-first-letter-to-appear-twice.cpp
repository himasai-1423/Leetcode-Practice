class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> us;
        
        for(int i=0; i<s.size(); i++){
            if(us.count(s[i]))
                return s[i];
            
            us.insert(s[i]);
        }
        return ' ';
    }
};