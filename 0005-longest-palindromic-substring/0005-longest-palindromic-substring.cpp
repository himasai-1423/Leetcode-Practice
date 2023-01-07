class Solution {
    int isPalindrome(string &s, int i, int j) {
        while(i>=0 && j<s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    }
public:
    string longestPalindrome(string &s) {
        int ans=0, start=0;
        for(int i=0; i<s.length(); i++) {
            int l1 = isPalindrome(s, i, i);
            int l2 = isPalindrome(s, i, i+1);

            int length = max(l1, l2);

            if(length > ans) {
                ans = length;
                start = i-(length-1)/2;
            }
        }

        return s.substr(start, ans);
    }
};