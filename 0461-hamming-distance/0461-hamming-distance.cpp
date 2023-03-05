class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, n = x^y;
        while(n) {
            if(n&1)
                res++;
            n>>=1;
        }
        return res;
    }
};