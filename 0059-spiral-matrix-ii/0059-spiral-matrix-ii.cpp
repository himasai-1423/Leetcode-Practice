class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int dir = 1, right = n-1, left = 0, up = 0, down = n-1;
        
       while(left<=right && up<=down) {
           if(dir == 1) {
               int i = left;
               while(i<=right) {
                   res[up][i]=num++;
                   i++;
               }
               up++;
               dir = 2;
           }
           
           else if(dir == 2) {
               int i = up;
               while(i<=down) {
                   res[i][right]=num++;
                   i++;
               }
               right--;
               dir = 3;
           }
           
           else if(dir == 3) {
               int i = right;
               while(i>=left) {
                   res[down][i]=num++;;
                   i--;
               }
               down--;
               dir = 4;
           }
           
           else {
               int i = down;
               while(i>=up) {
                   res[i][left]=num++;
                   i--;
               }
               left++;
               dir = 1;
           }
        }
        return res;
    }
};