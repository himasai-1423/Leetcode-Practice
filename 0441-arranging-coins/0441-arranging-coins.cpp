class Solution {
public:
    int arrangeCoins(int n) {
        int hi = n, lo = 0;
        
        while(hi>=lo) {
            int mid = lo+(hi-lo)/2;
            
            long coinsReq = (long)mid*(mid+1)/2;
            
            if(coinsReq==n)
                return mid;
            
            else if(coinsReq>n)
                hi = mid-1;
            
            else
                lo = mid+1;
        }
        return hi;
    }
};