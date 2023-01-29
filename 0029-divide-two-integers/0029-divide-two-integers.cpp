class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        bool signFinal = ((dividend>0)==(divisor>0));
        
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int res = 0;
        while(a>=b){
            int count=0;
            while(a > (b<<1<<count))
                count++;
            res += (1<<count);
            a -= (b<<count);
        }
        return signFinal?res:-res;
    }
};