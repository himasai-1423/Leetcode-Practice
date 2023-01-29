class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=0;
        for(int i=0; i<=31; i++){
            int a = (start>>i)&1;
            int b = (goal>>i)&1;
            if((a^b)==1)
                res++;
        }
        return res;
    }
};