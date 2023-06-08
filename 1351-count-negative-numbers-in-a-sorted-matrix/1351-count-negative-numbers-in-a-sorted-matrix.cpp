class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, negIdx = grid[0].size()-1;
        
        for(int i=0; i<grid.size(); i++) {
            while(negIdx>=0 && grid[i][negIdx]<0)
                negIdx--;
            
            res += (grid[0].size() - (negIdx+1));
        }
        return res;
    }
};