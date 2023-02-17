class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        if(n==1) return 0;
        
        vector<bool> check(n+1, true);
        
        for(int i=2; i<n; i++){
            if(check[i]){
                for(int j = 2*i; j<n; j+=i)
                    check[j]=false;
            }
        }
        
        for(int i=2; i<n; i++)
            if(check[i])
                res++;
        
        
        return res;
    }
};