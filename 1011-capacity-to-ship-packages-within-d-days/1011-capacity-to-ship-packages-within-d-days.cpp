class Solution {
public:
    bool checkPossibility(vector<int> &weights, int curWeight, int days) {
        int curDays = 1, shippedWeight = 0;
        
        for (int i: weights) {
            shippedWeight += i;
            
            if(shippedWeight>curWeight) {
                curDays++;
                shippedWeight = i;
            }
        }
        return curDays<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0, totalWeight=0;
        
        for (int i : weights) {
            totalWeight += i;
            maxWeight = max(maxWeight, i);
        }
        
        int l = maxWeight, r = totalWeight;
        while (l<r) {
            int cur = l+(r-l)/2;
            
            if(checkPossibility(weights, cur, days))
                r = cur;
            
            else
                l = cur+1;
        }
        return l;
    }
};