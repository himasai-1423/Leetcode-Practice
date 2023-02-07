class Solution {
public:
    int calcPow(int a, int b, int m){
        if(b==0) return 1;
        
        int temp = calcPow(a, b>>1, m);
        
        if(b&1){
            return ((a%m) * (temp%m)* (temp%m))%m;
        }
        
        else
            return ((temp%m) * (temp%m))%m;
    }
    
    int superPow(int a, vector<int>& b) {
        int ans = 1, m=1140;
        
        int valB = 0;
        for(int i=0; i<b.size(); i++){
            valB = ((10*valB) +b[i])%m;
        }
        
        if(valB == 0) valB = 1140;
        return calcPow(a, valB, 1337);
    }
};