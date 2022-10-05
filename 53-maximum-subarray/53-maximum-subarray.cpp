class Solution {
    struct value
    {
        int startLeft; 
        int endRight;
        int totalSum;
        int maxSum;
        value(int s, int e, int t, int m):startLeft(s), endRight(e), totalSum(t), maxSum(m){}
    };
    
    value divideAndConquer(vector<int> const& nums, int l, int r)
    {
        if (l==r)
        {
            return {nums[l], nums[l],nums[l],nums[l]};
        }
        
        int m = l + (r-l)/2;
        
        auto fromLeft=divideAndConquer(nums, l, m);
        auto fromRight=divideAndConquer(nums, m+1, r);
        
        int s = max(fromLeft.startLeft, fromLeft.totalSum+fromRight.startLeft);
        int e = max(fromRight.endRight, fromRight.totalSum+fromLeft.endRight);
        int t = fromLeft.totalSum + fromRight.totalSum;
        int ma = max(max(fromLeft.endRight+fromRight.startLeft, fromLeft.maxSum), fromRight.maxSum);
        
        return {s,e,t,ma};
        
    }
public:
    int maxSubArray(vector<int>& nums) {
        auto v = divideAndConquer(nums, 0, nums.size()-1);
        
        return v.maxSum;
    }
};