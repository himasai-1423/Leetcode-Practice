class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int i: nums) {
            if(i<0)
                sign *= -1;
            else if(i>0)
                sign *= 1;
            else  {
                sign = 0;
                break;
            }
        }
        return sign;
    }
};