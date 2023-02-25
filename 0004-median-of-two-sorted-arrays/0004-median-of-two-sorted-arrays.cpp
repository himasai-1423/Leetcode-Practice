class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(m<n)swap(nums1, nums2);
        int l = 0, r = nums1.size()-1;
        
        while(true) {
            int midN = l>r?-1:(l+(r-l)/2);
            int midM = (n+m)/2-(midN+1)-1;
            
            int left1, left2, right1, right2;
            
            left1 = midN>=0 ? nums1[midN] : INT_MIN;
            right1 = midN+1<nums1.size() ? nums1[midN+1] : INT_MAX;
            left2 = midM>=0 ? nums2[midM] : INT_MIN;
            right2 = midM+1<nums2.size() ? nums2[midM+1] : INT_MAX;
            
            if(left1<=right2 && left2<=right1) {
                if((n+m)%2)
                    return min(right1, right2);
                return (max(left1, left2)+min(right1, right2))/2.0;
            }
            
            else if (left1>right2)
                r = midN-1;
            
            else
                l = midN + 1;
//             int i = l > r ? -1 : (l + r) / 2;
//             int j = (n+m)/2 - (i+1) - 1;
            
//             int al = (i>=0?nums1[i]:INT_MIN);
//             int ar = (i + 1 < nums1.size() ? nums1[ i + 1 ] : INT_MAX);
//             int bl = (j>=0?nums2[j]:INT_MIN);
//             int br = (j + 1 < nums2.size() ? nums2[ j + 1 ] : INT_MAX);
            
//             if(al<=br && bl<=ar){
//                 if((n+m)%2)
//                     return min(ar,br);
//                 return (max(al,bl)+min(ar,br))/2.0;
//             }
//             else if(al>br) r = i-1;
//             else l = i+1;
        }
        return -1.0;
    }
};