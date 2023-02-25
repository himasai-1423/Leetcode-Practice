class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(m<n) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n-1;
        
        while(true) {
            int midN = l>r?-1:(l+(r-l)/2);
            int midM = (n+m)/2-(midN+1)-1;
            
            int left1, left2, right1, right2;
            
            left1 = midN>=0 ? nums1[midN] : INT_MIN;
            right1 = midN+1<n ? nums1[midN+1] : INT_MAX;
            left2 = midM>=0 ? nums2[midM] : INT_MIN;
            right2 = midM+1<m ? nums2[midM+1] : INT_MAX;
            
            if(left1<=right2 && left2<=right1) {
                if((n+m)%2)
                    return min(right1, right2);
                return (max(left1, left2)+min(right1, right2))/2.0;
            }
            
            else if (left1>right2)
                r = midN-1;
            
            else
                l = midN + 1;
        }
        return -1.0;
    }
};