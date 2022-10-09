class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat[0].size();
        int j=n-1;
        int sum=0;
        
        for(int i=0; i<n; i++){
            if(i==j){
                sum+=mat[i][i];
            }
            else{
                sum+=mat[i][i] + mat[i][j];
            }
            j--;
        }
        return sum;
    }
};