class Solution {
public:
    int check(string answerKey, int k, char ch) {
        int l=0, res = 0;
        for(int i=0; i<answerKey.size(); i++) {
            if(answerKey[i]!=ch) {
                k--;
                while(k<0) {
                    if(answerKey[l]!=ch) k++;
                    l++;
                }
            }
            res = max(res, i-l+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(check(answerKey, k, 'T'), check(answerKey, k, 'F'));
    }
};