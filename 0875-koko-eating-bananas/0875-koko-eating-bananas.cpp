class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int l=1, r = maxi, res = r;
        
        while(l<=r){
            int mid = (l+r)/2;
            double hours = 0;
            
            for(int i: piles)
                hours += ceil((double)i/mid);
            
            if(hours <= h){
                res = min(mid, res);
                r = mid-1;
            }
                
            else
                l=mid+1;
                
        }
        return res;
    }
};