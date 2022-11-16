/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int hi=n, lo = 1,mid, val ;
        
        while(hi>=lo){
            mid=lo+(hi-lo)/2;
            val=guess(mid);
            
            if(val==0) return mid;
            else if(val==1) lo=mid+1;
            else hi = mid-1;
        }
        return hi;
    }
};