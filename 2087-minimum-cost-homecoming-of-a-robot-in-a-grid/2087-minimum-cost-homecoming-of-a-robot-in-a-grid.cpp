class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int i = startPos[0], x = homePos[0], j = startPos[1], y = homePos[1], res =0;
        
        while(i != x){
            i += (x-i)/abs(x-i);
            res += rowCosts[i];
        }
        
        while(j != y){
            j += (y-j)/abs(y-j);
            res += colCosts[j];
        }
        
        return res;
    }
};