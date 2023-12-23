class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> m = {
            {'N', {0, 1}}, 
            {'S', {0, -1}}, 
            {'E', {1, 0}}, 
            {'W', {-1, 0}}
        }; 
    
        set<pair<int, int>> s;
        pair<int, int> loc = {0, 0};
        s.insert({0, 0});
        for(int i=0; i<path.size(); i++) {
            loc.first += m[path[i]].first;
            loc.second += m[path[i]].second;
            
            if(s.count(loc))
                return true;
            
            s.insert(loc);
        }
        return false;
    }
};