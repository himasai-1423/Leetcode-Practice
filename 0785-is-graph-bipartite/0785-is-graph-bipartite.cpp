class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        for(int i=0; i<graph.size(); i++) {
            if(color[i]==0 && !dfs(graph, 1, color, i))
                return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int c, vector<int>& color, int vertex){
        if(color[vertex]!=0) 
            return color[vertex]==c;
        
        color[vertex] = c;
        for(auto child: graph[vertex]) {
            if(!dfs(graph, -c, color, child))
                return false;
        }
        return true;
    }
};