class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        
        int dir = 1, right = n-1, left = 0, up = 0, down = m-1;
        
       while(left<=right && up<=down) {
           if(dir == 1) {
               int i = left;
               while(i<=right) {
                   res.push_back(matrix[up][i]);
                   i++;
               }
               up++;
               dir = 2;
           }
           
           else if(dir == 2) {
               int i = up;
               while(i<=down) {
                   res.push_back(matrix[i][right]);
                   i++;
               }
               right--;
               dir = 3;
           }
           
           else if(dir == 3) {
               int i = right;
               while(i>=left) {
                   res.push_back(matrix[down][i]);
                   i--;
               }
               down--;
               dir = 4;
           }
           
           else {
               int i = down;
               while(i>=up) {
                   res.push_back(matrix[i][left]);
                   i--;
               }
               left++;
               dir = 1;
           }
        }
        return res;
    }
};