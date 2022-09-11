class Solution {
public:
    int arrangeCoins(int n) {
        long hi = n, lo =0, mid;
        long coinsReq;
        while(hi>=lo){
            mid = lo+(hi-lo)/2;
            coinsReq = mid*(mid+1)/2;
            
            if(coinsReq == n) return (int)mid;
            
            if(coinsReq>n) hi = mid-1;
            else lo = mid+1;
        }
        return (int)hi;
    }
};