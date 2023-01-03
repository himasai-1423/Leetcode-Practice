//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int dp[1010][1010];

class Solution{
  public:
    int cuttingRod(int price[], int length, int cutSize, int idx){
        if(length<=0 || cutSize<=0|| idx<0) return 0;
        
        if(dp[idx][length] != -1) return dp[idx][length];
        
        int val = 0;
        if(length-cutSize<0){
            val = 0 + cuttingRod(price, length, cutSize-1, idx-1);
        }
        else{
            int withCutting = price[idx] + cuttingRod(price, length-cutSize, cutSize, idx);
            int withoutCutting = cuttingRod(price, length, cutSize-1, idx-1);
            
            val = max(withCutting, withoutCutting);
        }
        
        return dp[idx][length] = val;
    }
  
    int cutRod(int price[], int n) {
        memset(dp, -1, sizeof(dp));
        int ans=0, maxi=INT_MIN;
        for(int i=0; i<n; i++){
            ans = cuttingRod(price, n, i+1, i);
            maxi = max(maxi, ans);
        }
        return maxi;
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