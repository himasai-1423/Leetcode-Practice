class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num;
        
        while(r>=l){
            long mid = l + ((r-l)>>1);
            if(mid*mid == num)
                return true;
            
            else if(mid>num/mid)
                r = mid-1;
            
            else
                l = mid+1;
        } 
        return false;
    }
};