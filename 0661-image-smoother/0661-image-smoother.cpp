class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));
        
        for(int i=0; i<img.size(); i++) {
            for(int j=0; j<img[0].size(); j++) {
                int count=0, sum=0;
                for(int x=i-1; x<=i+1; x++) {
                    for(int y=j-1; y<=j+1; y++) {
                        if(x>=0 && y>=0 && x<img.size() && y<img[0].size()) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }
                res[i][j] = sum/count;
            }
        }
        return res;
    }
};