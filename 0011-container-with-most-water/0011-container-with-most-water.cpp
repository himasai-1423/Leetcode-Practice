class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0, cur = 0;
        while(l<r) {
            int minH = min(height[l], height[r]);
            cur = minH * (r-l);
            res = max(cur, res);
            
            if(height[l]>height[r])
                r--;
            else
                l++;
        }
        return res;
    }
};