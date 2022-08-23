class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1) return x;
        
        int last = x, first = 0, ans;
        
        while(last>first){
            int mid = (first+ last)/2;
            if(mid == (x/mid)) return mid;
            
            else if(mid<=(x/mid)){
                first = mid + 1;
                ans = mid;
            }             
            else
                last = mid;
        }
        return ans;
    }
};