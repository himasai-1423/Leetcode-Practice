class Solution {
public:
    int calculateCost(int n, vector<int> &cost, vector<int> &dp){
        if(n<0) return 0;
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        
        if(dp[n] != -1) return dp[n];
        int mini = min(calculateCost(n-1, cost, dp), calculateCost(n-2, cost, dp));
        
        return dp[n]=mini+cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n+3,-1);
        
        return min(calculateCost(n-1, cost, dp), calculateCost(n-2, cost, dp));
    }
};