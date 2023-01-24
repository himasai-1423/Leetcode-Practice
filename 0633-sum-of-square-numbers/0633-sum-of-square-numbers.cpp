class Solution {
public:
    bool judgeSquareSum(int c) {
        long num;

        
        for(long i=0; i*i<=c; i++){
            num = c-i*i;
            long hi = num, lo=0;
            while(hi>=lo){
                long mid = lo+(hi-lo)/2;
            
                if(mid*mid==num) return true;
                else if(mid*mid>num) hi = mid-1;
                else lo = mid+1;
            }        
        }
        return false;
    }
};