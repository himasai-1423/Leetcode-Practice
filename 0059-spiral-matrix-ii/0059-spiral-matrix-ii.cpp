class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int dir = 1, num = 1;
        int left = 0, right = n-1, top = 0, down = n-1;
        
        while(left<=right && top<=down) {
            if(dir==1) {
                int i = left;
                while(i<=right) {
                    res[top][i] = num++;
                    i++;
                }
                dir = 2;
                top++;
            }
            
            else if(dir==2) {
                int i = top;
                while(i<=down) {
                    res[i][right] = num++;
                    i++;
                }
                dir = 3;
                right--;
            }
            
            else if(dir==3) {
                int i = right;
                while(i>=left) {
                    res[down][i] = num++;
                    i--;
                }
                dir = 4;
                down--;
            }
            
            else {
                int i = down;
                while(i>=top) {
                    res[i][left] = num++;
                    i--;
                }
                dir = 1;
                left++;
            }
        }
        return res;
    }
};