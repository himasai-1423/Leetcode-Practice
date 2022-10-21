class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit1=0, profit2=0;
        int min1=INT_MAX, min2=INT_MAX;
        for(int i=0; i<prices.size(); i++){
            min1 = min(min1, prices[i]);
            profit1 = max(profit1, prices[i]-min1);
            
            min2 = min(min2, prices[i]-profit1);
            profit2 = max(profit2, prices[i]-min2);
        }
        return profit2;
    }
};