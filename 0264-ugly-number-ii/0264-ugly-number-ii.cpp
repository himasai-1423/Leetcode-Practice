class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> k(n);
        
        int m2=0, m3=0, m5=0;
        k[0]=1;
        for(int i=1; i<n; i++) {
            k[i] = min(k[m2]*2,min(k[m3]*3, k[m5]*5));
            
            if(k[i]==k[m2]*2) m2++;
            if(k[i]==k[m3]*3) m3++;
            if(k[i]==k[m5]*5) m5++;
        }
        return k[n-1];
    }
};