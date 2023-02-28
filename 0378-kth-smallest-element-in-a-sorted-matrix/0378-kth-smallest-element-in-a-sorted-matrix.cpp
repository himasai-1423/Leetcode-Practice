class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int hi, lo;
        hi = matrix[n-1][n-1];
        lo = matrix[0][0];
        
        while(lo<hi) {
            int mid = lo+(hi-lo)/2, count = 0;
            
            for(int i=0; i<n; i++) 
                count+= upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            
            if(count>=k) 
                hi = mid;
            
            else
                lo = mid+1;
        }
        return lo;
    }
};