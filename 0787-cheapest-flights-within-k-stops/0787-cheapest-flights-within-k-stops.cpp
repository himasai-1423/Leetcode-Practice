class Solution {
public:
    int INF = 1e9+10;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INF);
        dist[src] = 0;
        
        for(int i=0; i<=k; i++) {
            vector<int> temp(dist);
            for(auto &flight: flights) {
                if(dist[flight[0]] != INF)
                    temp[flight[1]]=min(temp[flight[1]], dist[flight[0]]+flight[2]);
            }
            dist = temp;
        }
        return dist[dst] == INF ? -1 :  dist[dst];
    }
};