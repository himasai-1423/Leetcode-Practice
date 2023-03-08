class Solution {
public:
    bool checkSpeed(vector<int>& piles, int rate, int h) {
        int time = 0;
        
        for(int i : piles) {
            time += ceil((double)i/rate);
        }
        
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        
        while(lo<hi) {
            int mid = lo + (hi-lo)/2;
            
            if(checkSpeed(piles, mid, h)) 
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};