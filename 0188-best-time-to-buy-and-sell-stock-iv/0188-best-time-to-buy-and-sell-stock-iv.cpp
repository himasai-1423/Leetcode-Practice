class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> minBuy(k, INT_MAX), maxSell(k, 0);
        
        for(int i=0; i<prices.size(); i++){
            for(int j=0; j<k; j++){
                minBuy[j] = min(minBuy[j], prices[i] - (j>0?maxSell[j-1]:0));
                maxSell[j] = max(maxSell[j], prices[i]-minBuy[j]);
            }
        }
        return maxSell[k-1];
    }
};