class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> walls;
        for(auto &building: buildings) {
            walls.push_back({building[0], -building[2]});
            walls.push_back({building[1], building[2]});
        }
        sort(walls.begin(), walls.end());
        
        multiset<int> height;
        height.insert(0);
        int top = 0;
        for(auto &wall: walls) {
            if(wall.second<0)
                height.insert(-wall.second);
            else
                height.erase(height.find(wall.second));
            
            if(*height.rbegin()!=top) {
                res.push_back({wall.first, *height.rbegin()});
                top = *height.rbegin();
            }
        }
        
        return res;
    }
};