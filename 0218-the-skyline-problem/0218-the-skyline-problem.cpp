class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> walls;
        vector<vector<int>> res;
        
        for(auto &b: buildings) {
            walls.push_back({b[0], -b[2]});
            walls.push_back({b[1], b[2]});
        }
        sort(walls.begin(), walls.end());
        
        multiset<int> wallHeights;
        wallHeights.insert(0);
        int top = 0;        
        for(auto wall: walls) {
            if(wall.second<0)
                wallHeights.insert(-wall.second);
            else
                wallHeights.erase(wallHeights.find(wall.second));
            
            vector<int> ans;
            if (*wallHeights.rbegin() != top) {
                ans.push_back(wall.first);
                ans.push_back(*wallHeights.rbegin());
                top=*wallHeights.rbegin();
                res.push_back(ans);
            }
        }
        
        return res;
    }
};