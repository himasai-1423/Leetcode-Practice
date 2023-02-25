class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if(B.size()<A.size())swap(A,B);
        int l = 0, r = A.size()-1;
        while(true){
            int i = l > r ? -1 : (l + r) / 2;
            int j = (n+m)/2 - (i+1) - 1;
            
            int al = (i>=0?A[i]:INT_MIN);
            int ar = (i + 1 < A.size() ? A[ i + 1 ] : INT_MAX);
            int bl = (j>=0?B[j]:INT_MIN);
            int br = (j + 1 < B.size() ? B[ j + 1 ] : INT_MAX);
            
            if(al<=br && bl<=ar){
                if((n+m)%2)
                    return min(ar,br);
                return (max(al,bl)+min(ar,br))/2.0;
            }
            else if(al>br) r = i-1;
            else l = i+1;
        }
        return -1.0;
    }
};