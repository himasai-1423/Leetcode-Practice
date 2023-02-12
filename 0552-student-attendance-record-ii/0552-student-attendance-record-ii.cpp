class Solution {
public:
    int m = 1e9+7;
    int studentAttendanceRecord(int n, int a, int l, vector<vector<vector<int>>> &dp){        
        if(a==2 || l==3)
            return 0;
        
        if(n==0)
            return 1;
        
        if(dp[n][a][l]!= -1) return dp[n][a][l];
        
        int ans =0;
        
        ans = studentAttendanceRecord(n-1, a, 0, dp)%m;
        ans = (ans + studentAttendanceRecord(n-1, a+1, 0, dp)%m) %m;
        ans = (ans + studentAttendanceRecord(n-1, a, l+1, dp)%m)%m;
        
        return dp[n][a][l] = ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+7, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return studentAttendanceRecord(n, 0, 0, dp);
    }
};