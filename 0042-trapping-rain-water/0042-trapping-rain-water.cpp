class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1, res=0;
        int maxLeft = height[l], maxRight = height[r];

        while(l<r){
            if(height[l]<height[r]){
                l++;
                int val = maxLeft - height[l];
                
                if(val>0)
                    res += val;
                
                maxLeft = max(maxLeft, height[l]);
            }
            
            else{
                r--;
                int val = maxRight - height[r];
                
                if(val>0)
                    res += val;
                
                maxRight = max(maxRight, height[r]);
            }
        }
        return res;
    }
};