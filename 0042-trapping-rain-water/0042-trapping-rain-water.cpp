class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(), 0) , maxRight(height.size(), 0);
        int res = 0;

        for(int i=1; i<height.size(); i++)
            maxLeft[i] = max(maxLeft[i-1], height[i-1]); 

        for(int i=height.size()-2; i>=0; i--)
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        
         for(int i=0; i<height.size(); i++){
             int minVal = min(maxLeft[i], maxRight[i]) - height[i];
             
             if(minVal>0)
                 res += minVal;
         }
        return res;
    }
};