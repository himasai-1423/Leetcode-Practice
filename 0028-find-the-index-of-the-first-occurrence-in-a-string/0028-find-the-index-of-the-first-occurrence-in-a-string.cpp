class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        for(int i=0; i<haystack.size();i++) {
            int j = 0;
            for(j=0; j<n; j++) {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j==n)
                return i;
        }
        return -1;
    }
};