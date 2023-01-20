class Solution {
public:
    bool isPowerOfFour(long n) {
        return n && !(n & (n-1)) && !((n-1)%3);
    }
};