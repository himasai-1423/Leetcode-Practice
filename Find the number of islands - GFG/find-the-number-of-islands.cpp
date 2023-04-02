//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &vis) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]== '0' || vis[i][j])
            return;
            
        vis[i][j] = true;
        
        dfs(grid, i, j+1, vis);
        dfs(grid, i, j-1, vis);
        dfs(grid, i+1, j, vis);
        dfs(grid, i+1, j+1, vis);
        dfs(grid, i+1, j-1, vis);
        dfs(grid, i-1, j, vis);
        dfs(grid, i-1, j+1, vis);
        dfs(grid, i-1, j-1, vis);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(vis[i][j]==false && grid[i][j]=='1') {
                    res++;
                    dfs(grid, i , j, vis);
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends