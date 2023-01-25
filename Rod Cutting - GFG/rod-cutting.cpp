//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int rodCut(int price[], int idx, int n, vector<vector<int>> &dp){
        if(n<=0 || idx<0) return 0;
        
        int ans;
        
        if(dp[n][idx] != -1) return dp[n][idx];
        if(n-idx-1<0){
            int withoutCutting = rodCut(price, idx-1, n, dp);
            ans = withoutCutting;
        }
        
        else{
            int withCutting = price[idx] + rodCut(price, idx, n-(idx+1), dp);
            int withoutCutting = rodCut(price, idx-1, n, dp);
            
            ans = max(withCutting, withoutCutting);
        }
        
        return dp[n][idx]=ans;
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+5, vector<int>(n+5, -1));
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            res= max(res, rodCut(price, i, n, dp));
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends