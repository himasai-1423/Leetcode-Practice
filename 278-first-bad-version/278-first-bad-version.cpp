// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long long firstBadVersion(int n) {
        long long hi = n, lo = 1, mid;
        while(hi>lo){
            mid = (hi+lo)/2;
            
            if(isBadVersion(mid)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};