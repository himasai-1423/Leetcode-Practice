class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, diff;
        set<int> s;
        s.insert(prices[0]);
        for(int i=1; i<prices.size(); i++){
            diff = prices[i] - *s.begin();
            profit = max(profit, diff);
            s.insert(prices[i]);
        }
        
        if(profit<=0) return 0;
        
        return profit;
    }
};