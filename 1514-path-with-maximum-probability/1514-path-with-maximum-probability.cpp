class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        vector<bool> vis(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<double, int>> q;
        q.push({1.0 , start});
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;
        
        while(!q.empty()) {
            auto parNode = q.top();
            q.pop();
            double parProb = parNode.first;
            int parVer = parNode.second;
            
            if(vis[parVer]) continue;
            vis[parVer] = true;
            
            for(auto &child: adj[parVer]) {
                if(prob[child.first] < parProb * child.second) {
                    prob[child.first] = parProb * child.second;
                    q.push({prob[child.first], child.first});
                }
            }
        }
        
        return prob[end];
    }
};