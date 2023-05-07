class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX, totalSell = 0;
        
        for(int i=0; i<prices.size(); i++) {
            minBuy = min(minBuy, prices[i]);
            if(minBuy<prices[i]) {
                totalSell += (prices[i]-minBuy); 
                minBuy = prices[i];
            }
        }
        return totalSell;
    }
};