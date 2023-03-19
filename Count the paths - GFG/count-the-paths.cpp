//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int s,vector<int> adj[],int d,int &count){
        if(s==d)
            count=count+1;

        for(auto it:adj[s])
            dfs(it,adj,d,count);
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> adj[n];
	    int j, cnt=0;
	    
	    for(int i=0;i<edges.size();i++) {
	        j=0;
	        int u=edges[i][j];
	        int v=edges[i][j+1];
	        adj[u].push_back(v);
	    }
	    dfs(s,adj,d,cnt);
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends