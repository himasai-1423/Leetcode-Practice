class Solution {
public:
    int minOperations(string s) {
        char flag = '1';
        int oneCnt = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] != flag) 
                oneCnt++;
            
            if(flag == '1') 
                flag = '0';
             else 
                flag = '1';
        }
        
        flag = '0';
        int zeroCnt = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] != flag)
                zeroCnt++;
            
            if(flag == '1')
                flag = '0';
             else 
                flag = '1';
        }
        
        return min(zeroCnt, oneCnt);
    }
};