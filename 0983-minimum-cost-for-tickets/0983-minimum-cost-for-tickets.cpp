class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> day(begin(days), end(days));
        
        int dp[366] = {};
        
        for(int i=1; i<=365; i++){
            if(day.find(i) == day.end()) dp[i] = dp[i-1];
            
            else
                dp[i] = min({dp[i-1]+costs[0], dp[max(0, i-7)]+costs[1], 
                             dp[max(0, i-30)] + costs[2]});
            
        }
        return dp[365];
    }
};