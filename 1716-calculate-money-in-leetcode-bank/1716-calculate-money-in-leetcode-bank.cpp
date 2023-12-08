class Solution {
public:
    int nDaysSum(int val) {
        return (val+1)*val/2;
    }
    
    int totalMoney(int n) {        
        int quotient = n/7;
        int reminder = n%7;
        
        int res = 0, i = 0;
        
        for(i=0; i<quotient; i++) {
            res += (i*7) + nDaysSum(7);
        }
        
        if(reminder != 0)
            res += (i*reminder) + nDaysSum(reminder);
        
        return res;
    }
};