class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0], second = cost[1];
        int n = cost.size();
        
        for(int i=2; i<cost.size(); i++) {
            cost[i] = min(first, second) + cost[i];
            first = second;
            second = cost[i];
        }
        return min(first, second);
    }
};