class Solution {
public:
    int findMaxProfit(vector<int> &prices){
        int minBuy = INT_MAX, totalSell=0;
        
        for(int i=0; i<prices.size(); i++){
            minBuy = min(minBuy, prices[i]);
            if(minBuy<prices[i]){
                totalSell += (prices[i]-minBuy);
                minBuy = prices[i];
            }
        }
        return totalSell;
    }
    int maxProfit(int k, vector<int>& prices) {
        if(k>prices.size()/2){
           return findMaxProfit(prices);
        }
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