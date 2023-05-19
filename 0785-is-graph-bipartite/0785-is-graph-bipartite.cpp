class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        
        for(int i=0; i<graph.size(); i++) {
            if(color[i]==0  && !dfs(i, 1, color, graph))
                return false;
        }
        return true;
    }
    
    bool dfs(int node, int c, vector<int> &color, vector<vector<int>>& graph) {
        if(color[node]!=0) 
            return color[node] == c;
        
        color[node] = c;
        for(auto &child: graph[node]) {
            if(!dfs(child, -c, color, graph))
                return false;
        }
        return true;
    }
};