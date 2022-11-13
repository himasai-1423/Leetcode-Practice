class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(int i= 0; i<columnTitle.length();i++ ){
            char c = columnTitle[i];
            int d = c-'A'+1;
            res = res*26 + d;
        }
        return res;
    }
};