class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag, flag2, flag3;
        int n = word.size();
        
        flag = true;
        for(int i=0; i<n; i++){
            if(!isupper(word[i])){
                flag = false;
                break;
            }
                
        }
        
        if(flag) return true;
        
        flag2 = true;
        for(int i=0; i<n; i++){
            if(!islower(word[i])){
                flag2 = false;
                break;
            }
                
        }
        
        if(flag2) return true;
        
        flag3 = true;
        
        if(!isupper(word[0]))
            flag3 = false;
        
        for(int i=1; i<n; i++){
            if(!islower(word[i])){
                flag3 = false;
                break;
            }
                
            
        }
        
        if(flag3) return true;
        
        return false;
    }
};