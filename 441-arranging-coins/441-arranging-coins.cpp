class Solution {
public:
    int arrangeCoins(int n) {
        int hi = n, lo =0;
        long mid, coinsReq;
        while(hi>=lo){
            mid = lo+(hi-lo)/2;
            coinsReq = mid*(mid+1)/2;
            
            if(coinsReq == n) return mid;
            
            if(coinsReq>n) hi = mid-1;
            else lo = mid+1;
        }
        return hi;
    }
};