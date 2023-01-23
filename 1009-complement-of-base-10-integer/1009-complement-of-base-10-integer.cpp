class Solution {
public:
    int bitwiseComplement(int n) {
        int count = 1;
        
        while(count<n)
            count = (count<<1) | 1;
        
        return n^count;
    }
};