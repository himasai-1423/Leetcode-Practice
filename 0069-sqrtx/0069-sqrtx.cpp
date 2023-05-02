class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        
        int l = 0 , r = x, mid;
        while(l<=r) {
            mid = l + (r - l)/2;
            
            if(mid == x/mid) return mid;
            
            else if(mid<x/mid) 
                l = mid + 1;
            
            else
                r = mid- 1;
        }
        return r;
    }
};