class Solution {
public:
    bool checkRecord(string s) {
        int cntA=0, cntL=0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='A'){
                cntL=0;
                cntA++;
                if(cntA==2)
                    return false;
            }
            
            else if(s[i]=='L'){
                cntL++;
                if(cntL==3)
                    return false;
            }
                
            
            else
                cntL=0;
        }
        return true;            
    }
};