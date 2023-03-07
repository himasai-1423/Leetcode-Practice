class Solution {
public:
    bool findTime(vector<int> &time, long long availableTime, int totalTrips) {
        long long tripsCovered = 0;
        for (int t : time) 
            tripsCovered += availableTime/t;
        
        return tripsCovered>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int maxi = *max_element(time.begin(), time.end());
        
        long long left = 1, right = (long long)totalTrips*maxi;
        
        while(left<right) {
            long long mid = left + (right-left)/2;
            
            if(findTime(time, mid, totalTrips))
                right = mid;
            
            else
                left = mid+1;
        }
        return left;
    }
};