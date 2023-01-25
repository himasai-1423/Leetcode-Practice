class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy=INT_MAX, res = 0;
        
        for(int i=0; i<prices.size(); i++){
            minBuy = min(minBuy, prices[i]);
            if(prices[i]>minBuy){
                res += (prices[i]-minBuy);
                minBuy = prices[i];
            }
        }
        return res;
    }
};