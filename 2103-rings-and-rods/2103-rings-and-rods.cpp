class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, unordered_set<int>> m;
        int res = 0;
        
        for(int i=0; i<rings.size(); i+=2)
            m[rings[i+1]].insert(rings[i]);
        
        for(auto &i: m)
            if(i.second.size()==3)
                res++;
        
        return res;
    }
};