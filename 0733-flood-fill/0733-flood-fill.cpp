class Solution {
public:
    int directions[4][4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int oldColor;

    void fillCells(vector<vector<int>>& image,  int i, int j,int color) {
        image[i][j] = color;

        for(auto &direction : directions) {
            int x = i + direction[0];
            int y = j + direction[1];

            if(x>=image.size() || y>=image[0].size() || x<0 || y<0 || image[x][y] != oldColor)
                continue;
            
            fillCells(image, x, y, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        oldColor = image[sr][sc];
        if(image[sr][sc]!=color)
            fillCells(image, sr, sc, color);
        
        return image;
    }
};