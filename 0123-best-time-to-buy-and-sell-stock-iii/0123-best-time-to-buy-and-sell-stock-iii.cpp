class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy1=INT_MAX, minBuy2=INT_MAX;
        int maxSell1 = 0, maxSell2 = 0;
        
        for(int i=0; i<prices.size(); i++){
            minBuy1 = min(minBuy1, prices[i]);
            maxSell1 = max(maxSell1, prices[i]-minBuy1);
            minBuy2 = min(minBuy2, prices[i]-maxSell1);
            maxSell2 = max(maxSell2, prices[i]-minBuy2);
        }
        return maxSell2;
    }
};