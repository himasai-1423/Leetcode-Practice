class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for(int &i: prices) {
            if(i<firstMin) {
                secondMin = firstMin;
                firstMin = i;
            } else if(i<secondMin) {
                secondMin = i;
            }
        }
        
        if(money-firstMin-secondMin<0)
            return money;
        
        return money-firstMin-secondMin;
    }
};