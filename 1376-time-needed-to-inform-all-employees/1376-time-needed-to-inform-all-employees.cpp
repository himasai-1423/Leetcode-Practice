class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i<n; i++) {
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        
        int res = informTime[headID];
        queue<pair<int, int>> q;
        q.push({headID, res}); //node, dist
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
                
            for(auto &child: adj[node.first]) {
                if(child!=node.first) {
                    int reachTime = informTime[child] + node.second;
                    res = max(res, reachTime);
                    q.push({child, reachTime});
                }
            }
        }
        return res;
    }
};