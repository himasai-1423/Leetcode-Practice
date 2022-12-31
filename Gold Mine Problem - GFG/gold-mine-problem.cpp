//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int collectGold(vector<vector<int>> &M, int x, int y, int n, int m, vector<vector<int>> &dp){
        
        if(x<0 || x==n || y==m) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int digUp = collectGold(M, x-1, y+1, n, m, dp);
        int right = collectGold(M, x, y+1, n, m, dp);
        int digDown = collectGold(M, x+1, y+1, n, m, dp);
        
        int maxGold = max(max(digUp, right), digDown);
        
        return dp[x][y] = maxGold + M[x][y];
    }
    
    int maxGold(int n, int m, vector<vector<int>> M){
        int goldMax = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1)) ;
        
        for(int i=0; i<n; i++){
            int currentGold = collectGold(M, i, 0, n, m, dp);
            goldMax = max(goldMax, currentGold);
        }
        return goldMax;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends