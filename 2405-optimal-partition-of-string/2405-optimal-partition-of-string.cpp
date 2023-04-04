class Solution {
public:
    int partitionString(string s) {
        int i = 0, res = 1,flag = 0;
        while(i < s.size()){
            int val = s[i] - 'a';
            if( flag & (1<<val) ) {
                flag = 0;
                res++;
            }
            flag = flag | (1<<val);
            i++;
        }
        return res;
    }
};