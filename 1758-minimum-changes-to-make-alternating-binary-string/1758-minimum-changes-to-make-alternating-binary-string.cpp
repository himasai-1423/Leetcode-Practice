class Solution {
public:
    int minOperations(string s) {
        char flag = '1';
        int oneOddCnt = 0, zeroZeroCnt = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] != flag) 
                oneOddCnt++;
            else
                zeroZeroCnt++;
            
            if(flag == '1') 
                flag = '0';
             else 
                flag = '1';
        }
        
        return min(oneOddCnt, zeroZeroCnt);
    }
};