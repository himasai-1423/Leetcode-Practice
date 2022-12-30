//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int N= 1e3+10;
const int M = 1e9+7;
long long dp[N];
    
class Solution {
  public:
    long long int fib(long long int n){
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (fib(n-1)% M + fib(n-2)% M)%M;
    }
    long long int nthFibonacci(long long int n){
        // code here
        
        memset(dp, -1, sizeof(dp));
    
        return fib(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends