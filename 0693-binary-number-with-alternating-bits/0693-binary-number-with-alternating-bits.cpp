class Solution {
public:
    bool hasAlternatingBits(long n) {
        long a = n^(n>>1);
        
        return (a&(a+1))==0;
    }
};