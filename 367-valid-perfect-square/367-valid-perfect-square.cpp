class Solution {
public:
    bool isPerfectSquare(int num) {
        long hi = num, lo = 1, mid;
        
        while(hi>=lo){
            mid = lo+(hi-lo)/2;
            
            if(mid*mid==num) return true;
            else if(mid>num/mid) hi = mid-1;
            else lo = mid+1;
        }        
        return 0;
    }
};