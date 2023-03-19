class Solution {
public:
    void dfs(int i, int j, int curColor, int newColor, vector<vector<int>>& image) {
        if(i>=image.size() || j>=image[i].size()) return;
        if(i<0 || j<0) return;
        if(image[i][j] != curColor) return;
        
        image[i][j] = newColor;
        
        dfs(i+1, j, curColor, newColor, image);
        dfs(i-1, j, curColor, newColor, image);
        dfs(i, j-1, curColor, newColor, image);
        dfs(i, j+1, curColor, newColor, image);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
            dfs(sr, sc, image[sr][sc], color, image);
        return image;
    }
};