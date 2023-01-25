class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX, maxSell = INT_MIN;
        
        for(int i=0; i<prices.size(); i++){
            minBuy = min(minBuy, prices[i]);
            maxSell = max(maxSell, prices[i]-minBuy);
        }
        
        return maxSell;
    }
};