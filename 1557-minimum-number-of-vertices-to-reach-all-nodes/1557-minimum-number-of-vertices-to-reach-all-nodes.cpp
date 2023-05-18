class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<bool> incoming(n, false);
        
        for(auto edge: edges) 
            incoming[edge[1]] = true;
        
        for(int i=0; i<n; i++) {
            if(!incoming[i])
                res.push_back(i);
        }
        return res;
    }
};