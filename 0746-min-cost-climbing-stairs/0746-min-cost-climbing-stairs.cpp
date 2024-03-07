class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        
        dp[1] = cost[0];
        for(int i=1; i<cost.size(); i++) {
            dp[i+1] = min(dp[i-1], dp[i]) + cost[i];
         }
        
        return min(dp[cost.size()], dp[cost.size()-1]);
    }
};